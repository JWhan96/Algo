#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

#define X first
#define Y second

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
queue<pair<int, int>> q;
int arr[101][101];
int vis[101][101];
int N, M;

void bfs(int x, int y) {
  vis[x][y] = 1;
  q.push({x, y});
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nr = cur.X + dr[d];
      int nc = cur.Y + dc[d];
      if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
      if (arr[nr][nc] == 1 && vis[nr][nc] == 0) {
        q.push({nr, nc});
        vis[nr][nc] = vis[cur.X][cur.Y] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char c;
      cin >> c;
      arr[i][j] = c - '0';
    }
  }

  bfs(0, 0);

  cout << vis[N - 1][M - 1] << endl;

  return 0;
}