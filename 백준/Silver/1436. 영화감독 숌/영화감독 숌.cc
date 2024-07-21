#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int N;
string str;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int num = 666;
  int cnt = 1;
  while (cnt < N) {
    num++;
    str = to_string(num);
    if (str.find("666") != string::npos) {
      cnt++;
    }
  }
  cout << num << endl;  // N번째로 '666'을 포함한 숫자를 출력

  return 0;
}
