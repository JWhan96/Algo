#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int K;
  cin >> K;

  stack<int> st;
  unsigned int res = 0;
  for (int i = 0; i < K; i++) {
    int num;
    cin >> num;
    if (st.size() != 0 && num == 0) {
      res -= st.top();
      st.pop();
      continue;
    }
    st.push(num);
    res += st.top();
  }
  cout << res;

  return 0;
}