#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a, bomb;
  string st = "";
  cin >> a >> bomb;
  int a_len = a.size();
  int bomb_len = bomb.size();
  int st_len = st.size();

  for (int i = 0; i < a.size(); i++) {
    st += a[i];  // 문자 추가
    // 임시 문자 길이가 폭발 문자열 보다 크거나 같을 때
    if (st.size() >= bomb.size()) {
      // cout << st << endl;
      bool flag = true;  // 폭발 문자열 있는지 확인하는 flag
      for (int j = 0; j < bomb.size(); j++) {
        if (st[st.size() - bomb.size() + j] != bomb[j]) {
          flag = false;
          break;
        }  // t뒤에서 폭발 문자열 길이만큼 비교
      }

      if (flag)  // 폭발 문자열일 경우 삭제
                 // st.erase(st.end() - bomb.size(), st.end());
        for (int i = 0; i < bomb.size(); i++) {
          st.pop_back();
        }
    }
  }
  if (st.empty())  // 남아 있는 문자열이 없는 경우
    cout << "FRULA" << '\n';
  else
    cout << st << '\n';
  return 0;
}
