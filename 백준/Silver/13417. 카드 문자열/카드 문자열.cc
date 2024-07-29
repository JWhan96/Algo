#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#define endl '\n'

using namespace std;

// stack<char> s;
queue<char> q;
deque<char> dq;
int N;
int T;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    cin >> N;
    for (int n = 0; n < N; n++) {
      char a;
      cin >> a;
      q.push(a);
    }
    while (!q.empty()) {
      char b = q.front();
      q.pop();
      if (dq.empty()) {
        dq.push_back(b);
      } else {
        char c = dq.front();
        if (b <= c) {
          dq.push_front(b);
        } else {
          dq.push_back(b);
        }
      }
    }
    while (!dq.empty()) {
      char result;
      result = dq.front();
      cout << result;
      dq.pop_front();
    }
    cout << endl;
  }

  return 0;
}