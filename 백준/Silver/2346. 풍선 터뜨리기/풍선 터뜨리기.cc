#include <deque>
#include <iostream>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

struct Node {
  int num;
  int idx;
};

int main() {
  fastio;
  int N;
  cin >> N;
  deque<Node> dq;

  for (int i = 1; i <= N; ++i) {
    int a;
    cin >> a;
    dq.push_back({i, a});
  }

  while (!dq.empty()) {
    Node current = dq.front();
    cout << current.num << " ";
    dq.pop_front();

    int steps = current.idx;

    if (dq.empty()) break;

    if (steps > 0) {
      for (int i = 1; i < steps; ++i) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      for (int i = steps; i < 0; ++i) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }

  return 0;
}
