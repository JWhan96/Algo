#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int solution(vector<vector<int>> maps) {
  int n = maps.size();
  int m = maps[0].size();
  queue<pair<int, int>> q;
  int dis[101][101] = {};
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
    
  // if(maps[n-2][m-1] == 0 && maps[n-1][m-2] == 0) return -1;

  q.push({0, 0});
  dis[0][0] = 1;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = cur.X + dx[d];
      int ny = cur.Y + dy[d];

      if (nx < 0 | ny < 0 || nx >= n || ny >= m) continue;
      if (dis[nx][ny] > 0 || maps[nx][ny] == 0) continue;
      q.push({nx, ny});
      dis[nx][ny] = dis[cur.X][cur.Y] + 1;
    }
  }

  int answer = 0;
  if (dis[n - 1][m - 1] == 0) {
    answer = -1;
  } else {
    answer = dis[n - 1][m - 1];
  }

  return answer;
}