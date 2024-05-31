#include <iostream>
#include <queue>
#include <string>
using namespace std;

string a;
int n;
int num;
queue<int> q;
int result;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == "push") {
      cin >> num;
      q.push(num);
    } else if (a == "pop") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.front() << '\n';
        q.pop();
      }
    } else if (a == "front") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.front() << '\n';
      }
    } else if (a == "back") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.back() << '\n';
      }
    } else if (a == "empty") {
      if (q.empty()) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    } else if (a == "size") {
      cout << q.size() << '\n';
    }
  }

  return 0;
}
