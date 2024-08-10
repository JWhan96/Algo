#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;
using ll = long long;
ll a;
struct info {
  int start;
  int end;
  int person;
};
int N;
ll dp[100005][2];
int main() {
  fastio;
  cin >> N;
  vector<info> arr(N);
  for (int i = 0; i < N; i++) {
    int s, e, p;
    cin >> s >> e >> p;
    arr[i] = {s, e, p};
  }
  dp[0][1] = arr[0].person;
  dp[0][0] = 0;
  dp[1][1] = arr[1].person;
  dp[1][0] = arr[0].person;
  for (int i = 2; i < N; i++) {
    dp[i][1] = dp[i - 1][0] + arr[i].person;
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
  }
  cout << max(dp[N - 1][0], dp[N - 1][1]);
}