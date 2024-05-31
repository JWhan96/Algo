#include <iostream>
#include <stack>
#include <string>
using namespace std;
int n;
stack<char> s;
string ss;

string gu(string a) {
  while (!s.empty()) {
    s.pop();
  }
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '(') {
      s.push('(');

    } else {
      if (s.empty()) {
        return "NO";
      }
      s.pop();
    }
  }

  if (s.empty()) {
    return "YES";
  } else {
    return "NO";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> ss;
    cout << gu(ss) << '\n';
  }

  return 0;
}