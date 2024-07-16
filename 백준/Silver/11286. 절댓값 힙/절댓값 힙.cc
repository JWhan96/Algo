#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

struct downNode {
  int real;
  int number;
  bool operator<(downNode right) const {
    if (real < right.real) return false;
    if (real > right.real) return true;
    if (number < right.number) return false;
    if (number > right.number) return true;
    return false;
  }
};

int N;

priority_queue<downNode> dpq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a == 0) {
      if (dpq.empty()) {
        cout << 0 << endl;
      } else {
        int maxV = dpq.top().number;
        dpq.pop();
        cout << maxV << endl;
      }
    } else if (a != 0) {
      dpq.push({abs(a), a});
    }
  }
}
