#include <iostream>
#define endl '\n'
using namespace std;

int dp[20];
int N;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (int i = 4; i < 11; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }
  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    cout << dp[num] << endl;
  }
}