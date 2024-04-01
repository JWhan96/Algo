#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T;
int m, n, k;
int arr[51][51];
int visited[51][51];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
int cnt;
queue<pair<int, int>> q;

int main() {
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    memset(visited, 0, sizeof(visited));
    memset(arr, 0, sizeof(arr));
    cnt = 0;
    int from, to;
    cin >> m >> n >> k;
    int row, col;

    for (int i = 0; i < k; i++) {
      cin >> to >> from;
      arr[from][to] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == 0) {
          continue;
        }
        if (visited[i][j] == 1) {
          continue;
        }
        if (arr[i][j] == 1 && visited[i][j] != 1) {
          q.push(make_pair(i, j));
          visited[i][j] == 1;
        }

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
            if (arr[nr][nc] == 0) {
              continue;
            }
            if (visited[nr][nc] == 1) {
              continue;
            }
            if (arr[nr][nc] == 1 && visited[nr][nc] != 1) {
              q.push(make_pair(nr, nc));
              visited[nr][nc] = 1;
            }
          }
        }
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
