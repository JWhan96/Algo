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
  visit[nowRow][nowCol] = 1;  //  여기서 한번 처리
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
  // visit[nr][nc] = 1;  // 처음 dfs들어오기전에 처리 후 다음 지나가는거 처리
  DFS(nr, nc);
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
      if (visit[i][j] != 0) continue;
      // visit[i][j] = 1;
      DFS(i, j);
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