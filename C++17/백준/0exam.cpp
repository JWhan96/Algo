#include <bits/stdc++.h>

#include <string>
#include <vector>

using namespace std;

#define X first
#define Y second

int solution(vector<string> board) {
  int answer = 0;
  int n, m;
  int dis[101][101] = {};
  queue<pair<int, int>> q;
  int dx[] = {0, 1, -1, 0};
  int dy[] = {1, 0, 0, -1};
  // for(int i =0; i<board.size(); i++   ){
  //     for(int j=0; j<board[i].size(); j++){
  //         cout << board[i][j];
  //     }
  //     cout << endl;
  // }
  n = board.size();
  m = board[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'R') {
        q.push({i, j});
        dis[i][j] = 10e5;
      }
      if (board[i][j] == 'D') dis[i][j] = 10e6;
    }
  }
  int cnt = 1;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = cur.X + dx[d];
      int ny = cur.Y + dy[d];
      if (nx < 0 || ny < 0 | nx >= n || ny >= m) continue;
      if (board[nx][ny] == 'D') continue;
      dis[nx][ny] = cnt;
      q.push({nx, ny});
      while (true) {
        auto nextCur = q.front();
        q.pop();
        int nxx = nextCur.X + dx[d];
        int nyy = nextCur.Y + dy[d];
        if (nxx < 0 || nyy < 0 | nxx >= n || nyy >= m ||
            board[nxx][nyy] == 'D') {
          q.push({nextCur.X, nextCur.Y});
          dis[nextCur.X][nextCur.Y] = cnt;
          cnt++;
          break;
        }
        dis[nxx][nyy] = cnt;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dis[i][j];
    }
    cout << endl;
  }

  return answer;
}