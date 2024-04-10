#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct pose {
  int row;
  int col;
  int wall;
  int cnt;
  bool day;
};
int n, m, k;
int arr[1001][1001];
int visited[1001][1001][11];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
queue<pose> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char a;
      cin >> a;
      arr[i][j] = a - '0';
    }
  }
  q.push({1, 1, 0, 1, 0});
  visited[1][1][0] = 1;
  while (!q.empty()) {
    int row = q.front().row;
    int col = q.front().col;
    int wall = q.front().wall;
    int cnt = q.front().cnt;
    bool day = q.front().day;
    q.pop();
    if (row == n && col == m) {
      cout << cnt;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr >= 1 && nc >= 1 && nr <= n && nc <= m) {
        if (arr[nr][nc] == 1 && wall != k && visited[nr][nc][wall + 1] == 0) {
          if (day == 0) {
            q.push({nr, nc, wall + 1, cnt + 1, !day});
            visited[nr][nc][wall + 1] = 1;
          } else {
            q.push({row, col, wall, cnt + 1, !day});
          }
        }
        if (arr[nr][nc] == 0 && visited[nr][nc][wall] == 0) {
          q.push({nr, nc, wall, cnt + 1, !day});
          visited[nr][nc][wall] = 1;
        }
      }
    }
  }
  cout << -1;
  return 0;
}