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
typedef long long ll;

int N;
pair<ll, ll> dp[100];
int main() {
  fastio;
  cin >> N;
  dp[1] = {0, 1};
  dp[2] = {1, 0};
  for (int i = 3; i <= N; i++) {
    ll c0 = dp[i - 1].first + dp[i - 1].second;
    ll c1 = dp[i - 2].second + dp[i - 2].first;
    dp[i] = {c0, c1};
  }
  cout << dp[N].first + dp[N].second;
}
