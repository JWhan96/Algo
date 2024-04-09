#include <iostream>
#include <queue>

using namespace std;

struct pose {
  int row;
  int col;
  int cnt;
};
int arr[1001][1001];
int visited[1001][1001];
int n, m;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
queue<pose> q;
int day;

int main() {
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int rc;
      cin >> rc;
      arr[i][j] = rc;
      if (rc == 1) {
        q.push({i, j, 0});
        visited[i][j] = 1;
      }
      if (rc == -1) {
        visited[i][j] = -1;
      }
    }
  }
  while (!q.empty()) {
    pose now = q.front();
    day = now.cnt;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = now.row + dr[i];
      int nc = now.col + dc[i];
      if (visited[nr][nc] != 0) {
        continue;
      }
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
        continue;
      }
      q.push({nr, nc, now.cnt + 1});
      visited[nr][nc] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j] == 0) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << day;
  return 0;
}