#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pose {
  int row;
  int col;
};
int N, M;
int K;
int arr[101][101];
int visit[101][101];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<pose> q;
vector<int> v;
int rcnt;

void bfs(int row, int col) {
  visit[row][col] = 1;
  q.push({row, col});
  rcnt = 1;
  while (!q.empty()) {
    int row = q.front().row;
    int col = q.front().col;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr < 0 || nc < 0 || nr >= N || nc >= M) {
        continue;
      }
      if (arr[nr][nc] != 0 || visit[nr][nc] != 0) {
        continue;
      }
      q.push({nr, nc});
      rcnt += 1;
      visit[nr][nc] = 1;
    }
  }
}
int main() {
  cin >> M >> N >> K;
  for (int i = 0; i < K; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int j = a; j < c; j++) {
      for (int k = b; k < d; k++) {
        arr[j][k] = 1;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == 1 || visit[i][j] == 1) {
        continue;
      } else {
        rcnt = 0;
        bfs(i, j);
        v.push_back(rcnt);
      }
      // cout << arr[i][j] << " ";
    }
    // cout << endl;
  }
  sort(v.begin(), v.end());
  cout << v.size() << "\n";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}