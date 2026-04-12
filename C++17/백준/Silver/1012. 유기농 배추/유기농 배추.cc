#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

#define X first
#define Y second

int dc[] = {0, 1, 0, -1};
int dr[] = {1, 0, -1, 0};
int arr[51][51];
bool vis[51][51];
int m, n, k;
queue<pair<int, int>> q;

void bfs(int x, int y) {
  vis[x][y] = true;
  q.push({x, y});
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nr = cur.X + dr[d];
      int nc = cur.Y + dc[d];
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
      if (arr[nr][nc] != 1 || vis[nr][nc]) continue;

      vis[nr][nc] = true;
      q.push({nr, nc});
    }
  }

  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    int cnt = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
      int r, c;
      cin >> r >> c;
      arr[r][c] = 1;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] || arr[i][j] != 1) continue;
        bfs(i, j);
        cnt++;
      }
    }

    cout << cnt << endl;
    memset(vis, 0, sizeof(vis));
    memset(arr, 0, sizeof(arr));
  }

  return 0;
}