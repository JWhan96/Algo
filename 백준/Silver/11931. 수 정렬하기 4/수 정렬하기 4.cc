#include <algorithm>
#include <iostream>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int N;
int main() {
  fastio;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), greater<int>());
  for (int s : v) {
    cout << s << endl;
  }
}
