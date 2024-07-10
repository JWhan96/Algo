#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

<<<<<<< HEAD
  == == == = cin >> N >> M;
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

>>>>>>> b92298f80e592e6da0bc997e6b474cd779169655
  return 0;
}