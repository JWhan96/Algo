#include <algorithm>
#include <iostream>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int N, M;
int main() {
  fastio;
  cin >> N >> M;
  int q = N + M;
  vector<int> v(q);
  for (int i = 0; i < q; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int s : v) {
    cout << s << " ";
  }
}
