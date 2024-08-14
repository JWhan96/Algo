#include <iostream>
#include <stack>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

struct Node {
  int row;
  int col;
};
int N, M;
int dat[100];
char arr[25][25];
int visit[25][25];
int cnt = 1;
int maxCnt = 1;
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

void dfs(int row, int col) {
  for (int i = 0; i < 4; i++) {
    int nr = row + dr[i];
    int nc = col + dc[i];
    if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
    if (visit[nr][nc] != 0) continue;
    if (dat[arr[nr][nc]] != 0) continue;
    visit[nr][nc] = 1;
    dat[arr[nr][nc]] = 1;
    cnt++;
    dfs(nr, nc);
    if (maxCnt < cnt) maxCnt = cnt;
    cnt--;
    visit[nr][nc] = 0;
    dat[arr[nr][nc]] = 0;
  }
}

int main() {
  fastio;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char a;
      cin >> a;
      arr[i][j] = a;
    }
  }

  visit[0][0] = 1;
  dat[arr[0][0]] = 1;
  dfs(0, 0);
  cout << maxCnt;
}
