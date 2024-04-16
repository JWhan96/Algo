#include <deque>
#include <iostream>
#include <string>
using namespace std;

string a;
int n;
int num;
deque<int> q;
int result;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == "push_front") {
      cin >> num;
      q.push_front(num);
    } else if (a == "push_back") {
      cin >> num;
      q.push_back(num);
    } else if (a == "pop_front") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.front() << '\n';
        q.pop_front();
      }
    } else if (a == "pop_back") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.back() << '\n';
        q.pop_back();
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
