#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct pose {
  int row;
  int col;
};
int N;
int arr[101][101];
int record[101][101];
int maxT = 0;
int area = 1;
int cnt;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
queue<pose> q;

void bfs(int row, int col) {
  record[row][col] = 1;
  q.push({row, col});
  while (!q.empty()) {
    int row = q.front().row;
    int col = q.front().col;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
        continue;
      }
      if (record[nr][nc] != 0) {
        continue;
      }
      q.push({nr, nc});
      record[nr][nc] = 1;
    }
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      arr[i][j] = a;
      if (maxT < a) {
        maxT = a;
      }
    }
  }
  for (int k = 1; k <= maxT; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (arr[i][j] <= k) {
          record[i][j] = 1;
        } else {
          record[i][j] = 0;
        }
      }
    }

    // bfs돌리면서 영역 찾기
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (record[i][j] == 0) {
          bfs(i, j);
          cnt += 1;
        }
      }
    }
    if (area < cnt) {
      area = cnt;
    }
    cnt = 0;
  }
  cout << area;

  return 0;
}