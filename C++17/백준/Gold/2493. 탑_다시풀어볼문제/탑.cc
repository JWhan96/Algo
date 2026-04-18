#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define height first
#define index second
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  stack<pair<int, int>> s;
  s.push({100000001, 0});
  for (int i = 1; i <= N; i++) {
    int num;
    cin >> num;
    while (s.top().height < num) {
      s.pop();
    }
    cout << s.top().index << " ";
    s.push({num, i});
  }

  return 0;
}