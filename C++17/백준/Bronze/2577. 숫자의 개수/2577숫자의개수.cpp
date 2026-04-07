#include <bits/stdc++.h>

using namespace std;

vector<int> arr(10);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int A, B, C;
  cin >> A >> B >> C;

  int res = A * B * C;
  string s = to_string(res);
  for (auto c : s) {
    arr[c - '0']++;
  }
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << "\n";
  }

  return 0;
}