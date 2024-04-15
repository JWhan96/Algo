#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long a, b;
int cnt;
long long arr[10000001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  int maxVal = sqrt(b) + 1;
  for (int i = 1; i <= maxVal; i++) {
    arr[i] = i;
  }
  for (int i = 2; i * i <= maxVal; i++) {
    if (arr[i] == 0) {
      continue;
    }
    for (int j = i * i; j <= maxVal; j += i) {
      arr[j] = 0;
    }
  }
  for (int i = 2; i <= maxVal; i++) {
    if (arr[i] != 0) {
      long long res;
      res = arr[i];

      while (arr[i] <= b / res) {
        res *= arr[i];
        if (res >= a) {
          cnt++;
        }
      }
      // while (arr[i] <= b / res) {
      //   if (res * arr[i] >= a) {
      //     cnt++;
      //   }
      //   res *= arr[i];
      // }
    }
  }
  cout << cnt;

  return 0;
}
