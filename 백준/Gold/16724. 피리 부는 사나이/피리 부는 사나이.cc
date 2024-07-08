#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
  bool operator==(const Node other) const {
    return row == other.row && col == other.col;
  }
  bool operator!=(const Node other) const {
    return !(row == other.row && col == other.col);
  }
};
int N, M;
Node parent[1001][1001];
char arr[1001][1001];
int visit[1001][1001];
int cnt;

Node Find(Node A) {
  if (A == parent[A.row][A.col]) {
    return A;
  };

  return parent[A.row][A.col] = Find(parent[A.row][A.col]);
  ;
}

void Union(Node A, Node B) {
  Node rootA = Find(A);
  Node rootB = Find(B);
  if (rootA == rootB) return;
  parent[B.row][B.col] = rootA;
}

void DFS(int nowRow, int nowCol) {
  visit[nowRow][nowCol] = 1;  //  질문 1. 그게 아닌 경우에는 여기서 한번 처리
  char nowS = arr[nowRow][nowCol];
  int nr, nc;
  nr = nowRow;
  nc = nowCol;
  if (nowS == 'D') {
    nr++;
  } else if (nowS == 'U') {
    nr--;
  } else if (nowS == 'L') {
    nc--;
  } else if (nowS == 'R') {
    nc++;
  }
  // 대표자도 같다면 생략?
  if (Find({nowRow, nowCol}) != Find({nr, nc})) {
    Union({nr, nc}, {nowRow, nowCol});
  }
  if (visit[nr][nc] != 0) return;
  DFS(nr, nc);
  // visit[nr][nc] = 1; // 질문 1. 미리 1처리 한 경우는 여기서 visit처리
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  // 부모 배열 초기화
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
      parent[i][j] = {i, j};
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visit[i][j] == 0) {
        // visit[i][j] = 1;  질문 1. 미리 1처리하고 들어갔을때 메모리 초과남
        DFS(i, j);
      }
      // 위랑 아래랑 시간 차이가 나는 이유(많이 차이나지는 않음)
      // if (visit[i][j] != 0) continue;
      // DFS(i, j);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cnt += (parent[i][j] == Node{i, j});
    }
  }

  cout << cnt << '\n';

  return 0;
}