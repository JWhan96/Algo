#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

int main() {
  fastio;
  string a, b;
  cin >> a >> b;

  int n = a.size();
  int m = b.size();

  // 2D DP 테이블 초기화
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  // DP를 통한 LCS 계산
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // 결과 출력
  cout << dp[n][m] << endl;

  return 0;
}
