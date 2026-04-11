#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int tc = 0; tc < N; tc++) {
    string s;
    cin >> s;
    list<char> l;
    auto cursor = l.end();
    for (auto c : s) {
      if (c == '<') {
        if (cursor != l.begin()) {
          cursor--;
        }
      } else if (c == '>') {
        if (cursor != l.end()) {
          cursor++;
        }
      } else if (c == '-') {
        if (cursor != l.begin()) {
          cursor--;
          cursor = l.erase(cursor);
        }
      } else {
        l.insert(cursor, c);
      }
    }
    for (auto it = l.begin(); it != l.end(); it++) {
      cout << *it;
    }
    cout << '\n';
  }
  return 0;
}