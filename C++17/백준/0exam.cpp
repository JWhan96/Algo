#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arrA[26] = {};
  int arrB[26] = {};

  string a, b;
  cin >> a >> b;

  for (auto aa : a) arrA[aa - 'a']++;
  for (auto bb : b) arrB[bb - 'a']++;

  int cnt = 0;

  for (int i = 0; i < 26; i++) {
    if (arrA[i] == arrB[i])
      continue;
    else {
      cnt += abs(arrA[i] - arrB[i]);
    }
  }

  cout << cnt;

  return 0;
}