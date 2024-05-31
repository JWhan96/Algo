#include <algorithm>
#include <iostream>

using namespace std;
int n;
int arr[10001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr[a] += 1;
  }
  for (int i = 1; i <= 10000; i++) {
    if (arr[i] == 0) {
      continue;
    } else {
      for (int j = 0; j < arr[i]; j++) {
        cout << i << '\n';
      }
    }
  }
}