#include <algorithm>
#include <iostream>

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int dp[30] = {};

int day[20];
int pay[20];
int N;

int main() {
  fastio;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int d, p;
    // cin >> d >> p;
    cin >> day[i] >> pay[i];
  }

  for (int i = 1; i <= N + 1; i++) {
    dp[i] = max(dp[i], dp[i - 1]);  // 이전날짜를 했을 경우와 안했을 경우 max

    dp[i + day[i]] =
        max(dp[i + day[i]],
            dp[i] + pay[i]);  // day만큼 일 못하므로 그 다음날의 최대 수익 계산
  }

  cout << dp[N + 1];
  return 0;
}