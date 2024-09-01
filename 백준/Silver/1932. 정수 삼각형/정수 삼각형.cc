#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;
typedef long long ll;

int N;
// pair<int, int>  dp[505];
int dr[] = {1, 1};
int dc[] = {0, 1};
int main() {
  fastio;
  cin >> N;
  vector<vector<int>> arr(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      int num;
      cin >> num;
      arr[i][j] = num;
    }
  }
  vector<vector<int>> dp(N, vector<int>(N, 0));
  dp[0][0] = arr[0][0];
  queue<pair<int, int>> q;
  q.push({0, 0});

  int maxNum = 0;
  while (!q.empty()) {
    int nowR = q.front().first;
    int nowC = q.front().second;
    q.pop();
    for (int i = 0; i < 2; i++) {
      int nextR = nowR + dr[i];
      int nextC = nowC + dc[i];
      if (nextR >= N || nextC >= N) continue;
      if (dp[nextR][nextC] >= dp[nowR][nowC] + arr[nextR][nextC]) continue;
      q.push({nextR, nextC});
      dp[nextR][nextC] =
          max(dp[nowR][nowC] + arr[nextR][nextC], dp[nextR][nextC]);
      // if (nextR == N - 1) {
      //   maxNum = max(maxNum, dp[nextR][nextC]);
      // }
    }
  }
  for (int i = 0; i < N; i++) {
    maxNum = max(maxNum, dp[N - 1][i]);
  }
  cout << maxNum;
}
