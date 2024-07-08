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
// int result[1001][1001];
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
  visit[nowRow][nowCol] = 1;  //  여기서 한번 처리 => 한번에 처리 가능하므로
                              //  가급적 이 방법으로 사용해보자
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
  Node rootNow = Find({nowRow, nowCol});
  Node rootNext = Find({nr, nc});

  if (rootNow != rootNext) {
    // Union({nowRow, nowCol}, {nr, nc});
    Union({nr, nc}, {nowRow, nowCol});
  }

  // if (rootNow == rootNext) return;
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
  // 1. Cnt구하는 1번 방법

  // for (int i = 0; i < N; ++i) {
  //   for (int j = 0; j < M; ++j) {
  //     Node res = Find(parent[i][j]);
  //     if (result[res.row][res.col] != 0) continue;
  //     result[res.row][res.col] = 1;
  //     cnt++;
  //   }
  // }

  // 1. Cnt구하는 2번 방법
  // 굳이 배열을 만들 필요없이 바로 구해서 메모리적으로 더 효율적

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cnt += (parent[i][j] == Node{i, j});
    }
  }

  cout << cnt << '\n';

  return 0;
}