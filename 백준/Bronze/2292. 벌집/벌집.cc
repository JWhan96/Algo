#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 1;
  int prev = 0;
  int cnt = 1;
  if (N == 1) {
    cout << 1;
    return 0;
  }
  while (true) {
    prev = 6 * cnt;
    cnt++;
    sum += prev;
    if (N <= sum) {
      break;
    }
  }
  cout << cnt;
  return 0;
}