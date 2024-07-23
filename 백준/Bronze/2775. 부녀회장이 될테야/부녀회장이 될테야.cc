#include <iostream>

using namespace std;

int result;
int fl;
int dp[15][15] = {
    0,
};
int line;
int T;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    cin >> fl >> line;

    for (int i = 0; i <= fl; i++) {
      int sum = 0;
      for (int j = 1; j <= line; j++) {
        // if (dp[i][j] != 0) continue;
        if (i == 0) {
          dp[i][j] = j;
        } else {
          sum += dp[i - 1][j];
          dp[i][j] = sum;
        }
      }
    }
    // for (int i = 0; i <= fl; i++) {
    //   for (int j = 1; j <= line; j++) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    cout << dp[fl][line] << endl;
  }

  return 0;
}