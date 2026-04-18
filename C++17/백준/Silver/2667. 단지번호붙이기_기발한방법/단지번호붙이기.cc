#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

#define X first
#define Y second

int N;
int arr[26][26];
int vis[26][26];
queue<pair<int, int>> q;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int res;             // 결과 값 - 벡터에 넣을 값
int part = 1;        // 동 구분값
vector<int> v = {};  // 정렬해서 순서대로 출력

void bfs(int x, int y) {
  vis[x][y] = part;
  res = 1;
  q.push({x, y});
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nr = cur.X + dr[d];
      int nc = cur.Y + dc[d];
      if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
      if (vis[nr][nc] != 0 || arr[nr][nc] == 0) continue;

      vis[nr][nc] = part;
      res++;
      q.push({nr, nc});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char c;
      cin >> c;
      arr[i][j] = c - '0';
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (vis[i][j] != 0 || arr[i][j] == 0) continue;
      bfs(i, j);
      v.push_back(res);
      part++;
    }
  }

  sort(v.begin(), v.end());

  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  return 0;
}