#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  list<int> l;
  for (int i = 1; i <= N; i++) {
    l.push_back(i);
  }
  // 첫 시작
  auto cur = l.begin();
  // list가 빌때까지
  cout << '<';
  while (!l.empty()) {
    for (int i = 0; i < K - 1; i++) {
      if (cur == l.end()) {
        cur = l.begin();
      }
      cur++;
      if (cur == l.end()) {
        cur = l.begin();
      }
    }

    int a = *cur;

    cur = l.erase(cur);
    if (l.size() != 0) {
      cout << a << ", ";

    } else {
      cout << a;
    }
  }
  cout << '>';

  return 0;
}