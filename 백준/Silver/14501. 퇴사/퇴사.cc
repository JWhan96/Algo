#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int N;
int dp[17][17];
int main() {
  fastio;
  cin >> N;
  vector<pair<int, int>> v(N + 1);
  for (int i = 1; i <= N; i++) {
    int d, p;
    cin >> d >> p;
    v[i] = {d, p};
  }

  int max_R = 0;
  for (int i = 1; i <= N; i++) {
    int max_C = 0;
    for (int k = 0; k < i; k++) {
      max_C = max(dp[k][i], max_C);
      // cout << "dp " << dp[k][i] << " " << "mc " << max_C << " ";
    }
    // cout << endl;
    // cout << max_C << endl;
    for (int j = 0; j <= N; j++) {
      int day = v[i].first;
      int pay = v[i].second;
      if (j > 0 && j < i) continue;
      if (j == 0) {
        dp[i][j] = max_R;
        continue;
      }

      if (j == i) {
        if (i + day - 1 > N) break;
        dp[i][j] = max_C + pay;
        max_R = max(max_R, dp[i][j]);
        j += day - 1;
        continue;
      }
      if (j > 0) {
        // if (j + day - 1 > N) continue;
        dp[i][j] = max_C + pay;
        max_R = max(max_R, dp[i][j]);
      }
    }
  }

  cout << max_R;
}
