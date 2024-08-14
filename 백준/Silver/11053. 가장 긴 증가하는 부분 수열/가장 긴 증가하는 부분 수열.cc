#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

int N;
int cnt = 0;

int main() {
  fastio;
  cin >> N;
  vector<int> dp(N, 1);
  vector<int> arr(N);

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    arr[i] = num;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  sort(dp.begin(), dp.end());
  cout << dp[N - 1];
}
