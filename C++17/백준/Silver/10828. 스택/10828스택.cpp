#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  stack<int> stk;
  string cmd;

  for (int i = 0; i < N; ++i) {
    cin >> cmd;

    if (cmd == "push") {
      int x;
      cin >> x;
      stk.push(x);
    } else if (cmd == "pop") {
      if (stk.empty())
        cout << -1 << '\n';
      else {
        cout << stk.top() << '\n';
        stk.pop();
      }
    } else if (cmd == "size") {
      cout << stk.size() << '\n';
    } else if (cmd == "empty") {
      cout << (stk.empty() ? 1 : 0) << '\n';
    } else if (cmd == "top") {
      cout << (stk.empty() ? -1 : stk.top()) << '\n';
    }
  }
  return 0;
}