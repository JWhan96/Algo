#include <algorithm>
#include <iostream>
#include <queue>
#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;
typedef long long ll;

int main() {
  fastio;
  int N, goal;
  cin >> N >> goal;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  int cnt = 0;
  sort(v.begin(), v.end(), greater<int>());
  for (int i = 0; i < N; i++) {
    while (goal - v[i] >= 0) {
      cnt++;
      goal -= v[i];
    }
  }
  cout << cnt;
}