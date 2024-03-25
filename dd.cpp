#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
char arr[101][101];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int visit[101][101];
int cnt = 1;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  int row = 0;
  int col = 0;
  visit[row][col] = 1;
  queue<pair<int, int>> q;
  q.push(make_pair(row, col));
  while (!q.empty()) {
    row = q.front().first;
    col = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
        continue;
      }
      if (visit[nr][nc] != 0) {
        continue;
      }
      if (arr[nr][nc] == '0') {
        continue;
      }
      if (arr[nr][nc] == '1') {
        q.push(make_pair(nr, nc));
        visit[nr][nc] = visit[row][col] + 1;
      }
      if (nr == n - 1 && nc == m - 1) {
        cout << visit[nr][nc];
        // return 0;
      }
    }
  }

  return 0;
}