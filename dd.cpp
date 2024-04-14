#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct pose {
  int row;
  int col;
};
int arr[9][9];
int brr[9][9];
int visit[9][9];
int cnt;
int n, m;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
queue<pose> q;
int result;
int c;
void copy_arr(int (*a)[9], int (*b)[9]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = b[i][j];
      // visit[i][j] = 0;
    }
  }
}
void bfs() {
  int crr[9][9];
  copy_arr(crr, brr);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (crr[i][j] == 2) {
        q.push({i, j});
      }
    }
  }
  c = cnt - 3;
  while (!q.empty()) {
    int row = q.front().row;
    int col = q.front().col;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
        continue;
      }
      if (crr[nr][nc] != 0) {
        continue;
      }
      if (crr[nr][nc] == 0) {
        crr[nr][nc] = 2;
        c--;
        q.push({nr, nc});
      }
    }
  }

  result = max(result, c);
}

void wall(int idx) {
  if (idx == 3) {
    bfs();
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (brr[i][j] == 0) {
        brr[i][j] = 1;
        wall(idx + 1);
        brr[i][j] = 0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  copy_arr(brr, arr);

  return 0;
}
