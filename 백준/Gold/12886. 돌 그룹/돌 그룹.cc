#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;
int visit[1505][1505];
int main() {
  fastio;
  int sum = 0;
  int A, B, C;
  cin >> A >> B >> C;
  sum = A + B + C;
  int result = sum / 3;

  if (sum % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  queue<pair<int, int>> q;
  q.push({A, B});
  visit[A][B] = 1;

  while (!q.empty()) {
    int a = q.front().first;
    int b = q.front().second;
    int c = sum - a - b;
    q.pop();

    int arr[3] = {a, b, c};
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        if (arr[i] < arr[j]) {
          int num1 = arr[i] * 2;
          int num2 = arr[j] - arr[i];
          if (visit[num1][num2] != 0) continue;

          visit[num1][num2] = 1;
          q.push({num1, num2});
        }
      }
    }
  }
  cout << visit[result][result];

  return 0;
}
