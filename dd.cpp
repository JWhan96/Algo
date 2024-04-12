#include <iostream>
#include <queue>

using namespace std;

struct pose {
  int row;
  int col;
};
int arr[9][9];
int visit[9][9];
int cnt;
int n, m;
int dr[] = {0, 1, 0, -1);
int dc[] = {1, 0, -1, 0};
queue<pose> q;

void bfs() {
  while (!q.empty()) {
    int row = q.front().row;
    int col = q.front().col;
  }
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) {
        cnt++;
      }
      if (arr[i][j] == 2) {
        q.push({i, j});
      }
    }
  }
  // 조합();
  int start_row = q.front().row;
  int start_col = q.front().col;
  visit[start_row][start_col] = 1;
  bfs();
  cout << cnt;
  return 0;
}
