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
  ll start;
  ll end;
  int person;
};
int N;
ll dp[100005];

bool compare(const info &a, const info &b) {
  return a.end != b.end ? a.end < b.end : a.start < b.start;
};

int main() {
  fastio;
  cin >> N;
  vector<info> arr(N);
  for (int i = 0; i < N; i++) {
    ll s, e;
    int p;
    cin >> s >> e >> p;
    arr[i] = {s, e, p};
  }
  sort(arr.begin(), arr.end(), compare);

  dp[0] = arr[0].person;
  for (int i = 1; i < N; i++) {
    auto it = lower_bound(
        arr.begin(), arr.begin() + i, arr[i],
        [](const info &a, const info &b) { return a.end < b.start; });

    int idx = it - arr.begin() - 1;

    dp[i] = max(dp[i - 1], (it != arr.begin() ? dp[idx] : 0) + arr[i].person);
  }

  cout << dp[N - 1] << endl;

  // for (auto i : arr) {
  //   cout << i.start << " " << i.end << " " << i.person << endl;
  // }
}