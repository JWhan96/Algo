#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  string st = "";
  int a_len = a.length();
  int b_len = b.length();
  for (int i = 0; i < a.length(); i++) {
    st += a[i];  // 문자 추가
    if (st.length() >=
        b_len) {  // 임시 문자 길이가 폭발 문자열 보다 크거나 같을 때
      bool flag = true;  // 폭발 문자열 있는지 확인하는 flag
      for (int j = 0; j < b_len; j++) {
        if (st[st.length() - b_len + j] != b[j]) {
          flag = false;
          break;
        }  // t뒤에서 폭발 문자열 길이만큼 비교
      }

      if (flag)  // 폭발 문자열일 경우 삭제
        st.erase(st.end() - b_len, st.end());
    }
  }
  if (st.empty())  // 남아 있는 문자열이 없는 경우
    cout << "FRULA" << '\n';
  else
    cout << st << '\n';
  return 0;
}
