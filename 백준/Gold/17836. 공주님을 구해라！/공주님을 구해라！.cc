#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct pose {
  int row;
  int col;
  int cnt;
  // bool sord;
};
int n, m, t;
int arr[101][101];
int visit[101][101];
int visit2[101][101];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
queue<pose> q;
int result1;
int result2;

void bfs() {
  while (!q.empty()) {
    int row = q.front().row;
    int col = q.front().col;
    int cnt = q.front().cnt;
    // bool sord = q.front().sord;
    q.pop();
    if (cnt > t) {
      result1 = 0;
      return;
    }
    if (row == n && col == m) {
      result1 = cnt;
      return;
    }
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr < 1 || nc < 1 || nr > n || nc > m) {
        continue;
      }
      if (visit[nr][nc] == 1 || arr[nr][nc] == 1) {
        continue;
      }
      q.push({nr, nc, cnt + 1});
      visit[nr][nc] = 1;
    }
  }

  return;
}
void bfs2() {
  while (!q.empty()) {
    int row = q.front().row;
    int col = q.front().col;
    int cnt = q.front().cnt;
    q.pop();
    if (cnt > t) {
      result2 = 0;
      return;
    }
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr < 1 || nc < 1 || nr > n || nc > m) {
        continue;
      }
      if (arr[nr][nc] == 2) {
        int nrow = nr;
        int ncol = nc;
        result2 = cnt + n - nrow + m - ncol + 1;
        if (result2 > t) {
          result2 = 0;
        }

        return;
      }
      if (visit2[nr][nc] == 1 || arr[nr][nc] == 1) {
        continue;
      }
      q.push({nr, nc, cnt + 1});
      visit2[nr][nc] = 1;
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }

  q.push({1, 1, 0});
  visit[1][1] = 1;
  bfs();
  q.push({1, 1, 0});
  visit2[1][1] = 1;
  bfs2();
  if (result1 == 0 && result2 == 0) {
    cout << "Fail";
  } else {
    if (result1 == 0) {
      cout << result2;
    } else if (result2 == 0) {
      cout << result1;
    } else {
      int re = min(result1, result2);
      cout << re;
    }
  }
  return 0;
}