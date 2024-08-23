#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int main() {
  fastio;
  int N;
  cin >> N;
  long long b = 1000000000;
  vector<vector<long long>> v(N + 1, vector<long long>(10, 0));
  for (int i = 1; i < 10; i++) {
    v[1][i] = 1;
  }
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0) {
        v[i][j] += v[i - 1][j + 1] % b;
      } else if (j == 9) {
        v[i][j] += v[i - 1][j - 1] % b;
      } else {
        v[i][j] += (v[i - 1][j - 1] + v[i - 1][j + 1]) % b;
      }
    }
  }

  long long result = 0;
  for (int i = 0; i < 10; i++) {
    result += v[N][i];
  }
  cout << result % b;
}