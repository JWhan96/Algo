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
  vector<long long> lis;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    auto it = lower_bound(lis.begin(), lis.end(), arr[i]);

    if (it == lis.end()) {
      lis.push_back(arr[i]);
    } else {
      *it = arr[i];
    }
  }

  cout << lis.size() << endl;
}
