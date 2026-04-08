#include <bits/stdc++.h>

using namespace std;

vector<int> arr(26);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int number, arr[10] = {}, cnt = 0;

  cin >> number;

  while (number > 0) {
    int res = number % 10;
    arr[res]++;
    number /= 10;
  }
  cnt = max(cnt, (arr[6] + arr[9] + 1) / 2);
  cout << cnt << " ";
  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9) continue;
    cnt = max(cnt, arr[i]);
    // cout << cnt << " ";
  }

  cout << cnt;

  return 0;
}