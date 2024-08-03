#include <iostream>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

int N, S;

int main() {
  fastio;
  cin >> N >> S;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    arr[i] = num;
  }
  int cnt = 0;
  for (int i = 0; i < (1 << N); i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        sum += arr[j];
      }
    }
    if (sum == S) {
      cnt++;
    }
  }
  if (S == 0) {
    cout << cnt - 1;
  } else {
    cout << cnt;
  }
}