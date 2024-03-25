#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int N;
char arr[30][30];
int visited[30][30];
int cnt;
vector<int> num_cnt;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int row, int col) {
  for (int i = 0; i < 4; i++) {
    int nr = row + dr[i];
    int nc = col + dc[i];
    if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
      // 맵바깥으로 넘어가는 경우 예외처리
      continue;
    }
    if (arr[nr][nc] == '0') {
      continue;
    }
    if (visited[nr][nc] == 1) {
      continue;
    }
    if (arr[nr][nc] == '1') {
      visited[nr][nc] = 1;
      cnt++;
      dfs(nr, nc);
    }
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (arr[i][j] == '1' && visited[i][j] != 1) {
        visited[i][j] = 1;
        cnt++;
        dfs(i, j);
        num_cnt.push_back(cnt);
        cnt = 0;
      }
    }
  }
  cout << num_cnt.size() << endl;
  sort(num_cnt.begin(), num_cnt.end());
  for (int i = 0; i < num_cnt.size(); i++) {
    cout << num_cnt[i] << endl;
  }

  return 0;
}