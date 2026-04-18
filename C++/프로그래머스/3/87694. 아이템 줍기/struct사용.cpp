#include <queue>
#include <string>
#include <vector>

using namespace std;

struct pos {
  int x, y, dis;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY,
             int itemX, int itemY) {
  int answer = 0;
  int rec = rectangle.size();
  queue<pos> q;
  int arr[102][102] = {};
  bool vis[102][102] = {};
  int dx[] = {0, 1, -1, 0};
  int dy[] = {1, 0, 0, -1};

  for (int i = 0; i < rec; i++) {
    for (int x = rectangle[i][0] * 2; x <= rectangle[i][2] * 2; x++) {
      for (int y = rectangle[i][1] * 2; y <= rectangle[i][3] * 2; y++)
        arr[x][y] = 1;
    }
  }

  for (int i = 0; i < rec; i++) {
    for (int x = (rectangle[i][0] * 2) + 1; x < rectangle[i][2] * 2; x++) {
      for (int y = (rectangle[i][1] * 2) + 1; y < rectangle[i][3] * 2; y++)
        arr[x][y] = 0;
    }
  }

  q.push({characterX * 2, characterY * 2, 0});
  vis[characterX * 2][characterY * 2] = 1;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    if (cur.x == itemX * 2 && cur.y == itemY * 2) {
      answer = cur.dis / 2;
      return answer;
    }

    for (int d = 0; d < 4; d++) {
      int nx = cur.x + dx[d];
      int ny = cur.y + dy[d];
      if (nx < 0 || ny < 0 || nx >= 102 || ny >= 102) continue;
      if (vis[nx][ny] > 0 || arr[nx][ny] == 0) continue;
      q.push({nx, ny, cur.dis + 1});
      vis[nx][ny] = 1;
    }
  }

  return answer;
}