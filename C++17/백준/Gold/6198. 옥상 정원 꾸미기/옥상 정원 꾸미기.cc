#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  stack<int> st;
  // st.push({1000000001, 0});
  long long res = 0;
  while (N--) {
    int h;
    cin >> h;

    if (st.size() == 0) {
      st.push(h);
      continue;
    }

    while (!st.empty() && st.top() <= h) {
      st.pop();
    }

    res += st.size();
    st.push(h);
  }

  cout << res;

  return 0;
}