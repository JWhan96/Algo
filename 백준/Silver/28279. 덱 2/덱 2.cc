#include <deque>
#include <iostream>
#define endl '\n'
using namespace std;

deque<int> dq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> dq;
  int n;
  cin >> n;  // 명령의 개수 입력

  for (int i = 0; i < n; ++i) {
    int command;
    cin >> command;

    if (command == 1) {
      int x;
      cin >> x;
      dq.push_front(x);
    } else if (command == 2) {
      int x;
      cin >> x;
      dq.push_back(x);
    } else if (command == 3) {
      if (!dq.empty()) {
        cout << dq.front() << endl;
        dq.pop_front();
      } else {
        cout << -1 << endl;
      }
    } else if (command == 4) {
      if (!dq.empty()) {
        cout << dq.back() << endl;
        dq.pop_back();
      } else {
        cout << -1 << endl;
      }
    } else if (command == 5) {
      cout << dq.size() << endl;
    } else if (command == 6) {
      cout << (dq.empty() ? 1 : 0) << endl;
    } else if (command == 7) {
      if (!dq.empty()) {
        cout << dq.front() << endl;
      } else {
        cout << -1 << endl;
      }
    } else if (command == 8) {
      if (!dq.empty()) {
        cout << dq.back() << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }

  return 0;
}