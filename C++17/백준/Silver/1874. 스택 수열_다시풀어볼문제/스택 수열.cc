#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  stack<int> st;
  string res;
  int inp = 1;
  for (int i = 1; i <= n; i++) {  // n개 입력
    int num;
    cin >> num;

    while (inp <= num) {
      st.push(inp);
      inp++;
      res += "+\n";
    }
    if (st.top() > num) {
      cout << "NO";
      return 0;
    }
    st.pop();
    res += "-\n";
  }

  cout << res;

  return 0;
}