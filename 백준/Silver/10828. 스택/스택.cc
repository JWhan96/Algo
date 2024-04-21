#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> s;
string ss;
int n;
int num;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ss;
    if (ss == "push") {
      cin >> num;
      s.push(num);
    } else if (ss == "pop") {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        cout << s.top() << '\n';
        s.pop();
      }
    } else if (ss == "size") {
      cout << s.size() << '\n';
    } else if (ss == "empty") {
      if (s.empty()) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }

    } else if (ss == "top") {
      if (s.empty()) {
        cout << -1 << '\n';

      } else {
        cout << s.top() << '\n';
      }
    }
  }
  return 0;
}