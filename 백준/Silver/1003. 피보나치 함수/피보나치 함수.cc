#include <iostream>
#define endl '\n'
using namespace std;

int dp[50] = {
    0,
    1,
    1,
};
int N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 3; i < 41; i++) {
    dp[i] = dp[i - 2] + dp[i - 1];
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (num == 0) {
      cout << 1 << " " << 0 << endl;
    } else if (num == 1) {
      cout << 0 << " " << 1 << endl;
    } else {
      cout << dp[num - 1] << " " << dp[num] << endl;
    }
  }
}