#include <iostream>
#include <queue>

using namespace std;

struct pose {
  int row;
  int col;
  int depth;
  int cnt;
};
int dr[] = {1, 0, -1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};
int dd[] = {0, 0, 0, 0, -1, 1};
int day;
int cnt0;
queue<pose> q;
int arr[101][101][101];
int visited[101][101][101];
int m, n, h;
int main() {
  cin >> m >> n >> h;
  for (int z = 0; z < h; z++) {
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        int rc;
        cin >> rc;
        arr[x][y][z] = rc;
        if (rc == 0) {
          cnt0++;
        }
        if (rc == 1) {
          q.push({x, y, z, 0});
          visited[x][y][z] = 1;
        }
        if (rc == -1) {
          visited[x][y][z] = -1;
        }
      }
    }
  }
  if (cnt0 == 0) {
    cout << 0;
    return 0;
  }
  while (!q.empty()) {
    pose now = q.front();
    day = now.cnt;
    q.pop();
    for (int i = 0; i < 6; i++) {
      int nr = now.row + dr[i];
      int nc = now.col + dc[i];
      int nd = now.depth + dd[i];
      if (nr < 0 || nc < 0 || nd < 0 || nr >= n || nc >= m || nd >= h) {
        continue;
      }
      if (visited[nr][nc][nd] != 0) {
        continue;
      }
      q.push({nr, nc, nd, now.cnt + 1});
      visited[nr][nc][nd] = 1;
    }
  }

  for (int z = 0; z < h; z++) {
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        if (visited[x][y][z] == 0) {
          cout << -1;
          return 0;
        }
      }
    }
  }
  cout << day;

  return 0;
}