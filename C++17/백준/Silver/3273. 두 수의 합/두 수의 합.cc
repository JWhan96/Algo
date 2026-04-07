#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, X, cnt = 0;
  cin >> N;
  map<int, int> m;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    m[num] += 1;
    arr[i] = num;
  }
  cin >> X;

  for (int i = 0; i < N; i++) {
    if (m[arr[i]] == 0) continue;
    if (m.count(X - arr[i]) == 0 || m[X - arr[i]] == 0) continue;
    if (arr[i] == X - arr[i]) {
      cnt += m[arr[i]] * (m[arr[i]] - 1) / 2;
      m[arr[i]] = 0;
    } else {
      cnt += m[arr[i]] * m[X - arr[i]];
      m[arr[i]] = 0;
      m[X - arr[i]] = 0;
    }
  }

  cout << cnt;

  return 0;
}