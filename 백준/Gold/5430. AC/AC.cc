#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <sstream>
using namespace std;

deque<int> dq;
bool reverse_flag;
int n;
string AC;
string num_arr;
bool result;
void init() {
  dq.clear();
  reverse_flag = false;
  result = false;
  n = 0;
}
void parseNumArr() {
  // 첫 번째와 마지막 문자(대괄호) 제거
  num_arr = num_arr.substr(1, num_arr.size() - 2);

  // stringstream을 사용하여 쉼표로 분리된 숫자 처리
  stringstream ss(num_arr);
  string item;
  while (getline(ss, item, ',')) {  // 쉼표를 기준으로 분리
    if (!item.empty()) {
      // 문자열을 정수로 변환하여 덱에 추가
      dq.push_back(stoi(item));
    }
  }
}
void input() {
  cin >> AC;
  cin >> n;
  cin >> num_arr;
}

void sol() {
  for (int i = 0; i < AC.size(); i++) {
    char check = AC[i];
    if (check == 'R') {
      reverse_flag = !reverse_flag;
    } else if (check == 'D' && dq.empty()) {
      result = true;
      return;
    } else if (reverse_flag == true && check == 'D') {
      dq.pop_back();
    } else if (reverse_flag == false && check == 'D') {
      dq.pop_front();
    }
  }
}

int T;
int main() {
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    init();
    input();
    parseNumArr();
    sol();

    if (result == false && !dq.empty() && reverse_flag == false) {
      cout << "[";
      for (int i = 0; i < dq.size(); i++) {
        cout << dq[i];
        if (i <
            dq.size() - 1) {  // 마지막 원소가 아니라면, 콤마와 공백을 추가한다.
          cout << ",";
        }
      }
      cout << "]";
    } else if (result == false && !dq.empty() && reverse_flag == true) {
      cout << "[";
      for (int i = dq.size() - 1; i >= 0; i--) {
        cout << dq[i];
        if (i > 0) {  // 마지막 원소가 아니라면, 콤마와 공백을 추가한다.
          cout << ",";
        }
      }
      cout << "]";
    } else if (result == false && dq.empty()) {
      cout << "["
           << "]";
    } else {
      cout << "error";
    }
    cout << endl;
  }
  return 0;
}

