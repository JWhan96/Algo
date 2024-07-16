#include <deque>
#include <iostream>
#include <queue>
#include <unordered_map>
#define endl '\n'

using namespace std;

struct upNode {
  long long number;
  bool operator<(upNode right) const {
    if (number > right.number) return false;
    if (number < right.number) return true;
    return false;
  }
};
struct downNode {
  long long number;
  bool operator<(downNode right) const {
    if (number < right.number) return false;
    if (number > right.number) return true;
    return false;
  }
};
int T;
int N;
priority_queue<upNode> upq;
priority_queue<downNode> dpq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    cin >> N;
    while (!upq.empty()) {
      upq.pop();
    }
    while (!dpq.empty()) {
      dpq.pop();
    }
    unordered_map<long long, int> visit;

    for (int nn = 0; nn < N; nn++) {
      char method;
      long long a;
      cin >> method >> a;

      if (method == 'I') {
        upq.push({a});
        dpq.push({a});
        visit[a]++;
      }
      if (method == 'D') {
        if (a == 1 && !upq.empty()) {
          while (!upq.empty() && visit[upq.top().number] == 0) {
            upq.pop();
          }
          if (visit[upq.top().number] != 0) {
            visit[upq.top().number]--;
            upq.pop();
          }

        } else if (a == -1 && !dpq.empty()) {
          while (!dpq.empty() && visit[dpq.top().number] == 0) {
            dpq.pop();
          }
          if (visit[dpq.top().number] != 0) {
            visit[dpq.top().number]--;
            dpq.pop();
          }
        }
      }
    }

    while (!upq.empty() && visit[upq.top().number] == 0) {
      upq.pop();
    }
    while (!dpq.empty() && visit[dpq.top().number] == 0) {
      dpq.pop();
    }

    if (upq.empty() || dpq.empty()) {
      cout << "EMPTY" << endl;
    } else {
      long long maxV, minV;
      maxV = upq.top().number;
      minV = dpq.top().number;
      cout << maxV << " " << minV << endl;
    }
  }
}
