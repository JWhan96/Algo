#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int main() {
  fastio;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    list<char> l;
    // for (int i = 0; i < s.size(); i++) {
    //   l.push_back(s[i]);
    // }
    auto cursor = l.end();
    for (auto c : s) {
      if (c == '<') {  // 커서를 왼쪽으로 이동
        if (cursor != l.begin()) cursor--;
      } else if (c == '>') {  // 커서를 오른쪽으로 이동
        if (cursor != l.end()) cursor++;
      } else if (c == '-') {  // 커서 왼쪽의 문자 삭제
        if (cursor != l.begin()) {
          cursor--;  // 삭제
          cursor = l.erase(cursor);
        }
      } else {
        l.insert(cursor, c);
      }
    }

    for (auto a : l) {
      cout << a;
    }
    cout << endl;
  }
}
