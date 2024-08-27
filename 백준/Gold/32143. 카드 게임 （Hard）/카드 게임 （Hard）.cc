#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int N, M;
int heal;

int main() {
  fastio;
  cin >> heal;
  cin >> N >> M;
  pair<int, int> result = {-1, 0};
  long long sum = 0;
  multiset<int, greater<int>> ms;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    ms.insert(num);
    sum += num;
  }
  if (sum < heal) {
    cout << -1 << endl;
  } else {
    int h1 = 0;
    int c1 = 0;
    int r1 = 0;
    for (auto a : ms) {
      h1 += a;
      c1++;
      if (h1 >= heal) {
        r1 = a;
        result = {c1, r1};
        break;
      }
    }
    cout << result.first << endl;
  }
  for (int i = 0; i < M; i++) {
    int num;
    cin >> num;
    sum += num;

    if (result.first != -1) {
      if (result.second >= num) {  // 같은경우도 넣나...?
        cout << result.first << endl;
      } else {
        ms.insert(num);
        int h1 = 0;
        int c1 = 0;
        int r1 = 0;
        for (auto a : ms) {
          h1 += a;
          c1++;
          if (h1 >= heal) {
            r1 = a;
            result = {c1, r1};
            break;
          }
        }
        cout << result.first << endl;
      }
    } else {
      ms.insert(num);
      if (sum < heal) {
        cout << -1 << endl;
      } else {
        int h1 = 0;
        int c1 = 0;
        int r1 = 0;
        for (auto a : ms) {
          h1 += a;
          c1++;
          if (h1 >= heal) {
            r1 = a;
            result = {c1, r1};
            break;
          }
        }
        cout << result.first << endl;
      }
    }
  }

  // cout << result.first << " " << result.second;
}