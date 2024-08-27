#include <iostream>
#include <queue>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

typedef long long ll;

void push(int x, int heal, ll &sum,
          priority_queue<int, vector<int>, greater<int>> &pq) {
  if (sum < heal) {
    sum += x;
    pq.push(x);
  } else if (x > pq.top()) {
    sum += x;
    pq.push(x);
    while (sum - pq.top() >= heal) {
      sum -= pq.top();
      pq.pop();
    }
  }
}

int main() {
  fastio;
  int heal;
  cin >> heal;
  int N, M;
  cin >> N >> M;
  ll sum = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  // auto push = [&](int x) {
  //   if (sum < heal) {
  //     sum += x;
  //     pq.push(-x);
  //   } else if (x > -pq.top()) {
  //     sum += x;
  //     pq.push(-x);
  //     while (sum - -pq.top() >= heal) {
  //       sum -= -pq.top();
  //       pq.pop();
  //     }
  //   }
  // };
  while (N--) {
    int x;
    cin >> x;
    push(x, heal, sum, pq);
  }
  cout << (sum >= heal ? (int)pq.size() : -1) << '\n';
  while (M--) {
    int x;
    cin >> x;
    push(x, heal, sum, pq);
    cout << (sum >= heal ? (int)pq.size() : -1) << '\n';
  }
}