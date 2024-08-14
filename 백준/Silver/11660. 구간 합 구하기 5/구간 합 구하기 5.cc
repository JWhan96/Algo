#include <iostream>
#include <stack>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

int arr[1030][1030];
int dp[1030][1030];
int N, M;
int main() {
  fastio;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      int num;
      cin >> num;
      arr[i][j] = num;
      sum += num;
      dp[i][j] = sum;
    }
  }
  for (int k = 0; k < M; k++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int result = 0;
    for (int i = r1; i <= r2; i++) {
      result += dp[i][c2] - dp[i][c1 - 1];
    }
    cout << result << endl;
  }
}

// 1 3 6 10
// 12 15 19 24
// 27 31 36 42
// 46 51 57 64

// 1 3 6 10
// 2 5 9 14
// 3 7 12 18
// 4 9 15 22
