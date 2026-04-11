#include <bits/stdc++.h>

using namespace std;

/*
L 커서 왼쪽
D 커서 오른쪽
B 커서 왼쪽 삭제
P $ 문자를 커서 왼쪽에 추가가
*/
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s = "";
  cin >> s;
  list<char> l = {};
  for (auto c : s) {
    l.push_back(c);
  }
  auto cur = l.end();
  int inNum;
  cin >> inNum;

  for (int i = 0; i < inNum; i++) {
    char inChar;
    cin >> inChar;
    if (inChar == 'L') {
      if (cur != l.begin()) cur--;
    }

    if (inChar == 'D') {
      if (cur != l.end()) cur++;
    }

    if (inChar == 'B') {
      if (cur != l.begin()) {
        cur--;
        cur = l.erase(cur);
      }
    }

    if (inChar == 'P') {
      char c;
      cin >> c;
      if (cur == l.end()) {
        l.push_back(c);
      } else {
        l.insert(cur, c);
      }
    }
  }

  for (auto it = l.begin(); it != l.end(); it++) {
    cout << *it;
  }

  return 0;
}