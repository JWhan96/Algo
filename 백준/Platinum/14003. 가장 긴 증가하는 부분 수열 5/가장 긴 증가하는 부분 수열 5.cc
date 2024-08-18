#include <algorithm>
#include <iostream>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

long long N;
int main() {
  fastio;
  cin >> N;
  vector<long long> arr(N);
  vector<int> dp(N, 1);
  vector<long long> lis;
  int idx = 0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    auto it = lower_bound(lis.begin(), lis.end(), arr[i]);

    if (it == lis.end()) {
      lis.push_back(arr[i]);
      dp[i] = lis.size();
      idx = i;
    } else {
      *it = arr[i];
      int posIdx = distance(lis.begin(), it);
      dp[i] = posIdx + 1;
    }
  }

  int dpIdx = lis.size();
  cout << dpIdx << endl;

  vector<long long> v(dpIdx);
  for (int i = N - 1; i >= 0; i--) {
    if (dp[i] == dpIdx) {
      v[--dpIdx] = arr[i];
    }
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
