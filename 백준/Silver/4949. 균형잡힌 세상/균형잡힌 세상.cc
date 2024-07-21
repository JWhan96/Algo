#include <iostream>
#include <stack>
#include <vector>
#define endl '\n'

using namespace std;

vector<string> arr;
bool endstring;
stack<char> small;

int main() {
  while (true) {
    string a;
    getline(cin, a);
    // cout << a[0] << endl;
    if (a[0] == '.') {
      break;
    }
    arr.push_back(a);
  }
  for (int i = 0; i < arr.size(); i++) {  // 문장돌기
    while (!small.empty()) {              // 초기화
      small.pop();
    }
    for (int j = 0; j < arr[i].size(); j++) {  // 문장내에서 돌기
      if (arr[i][j] == '[') {
        small.push('[');
      } else if (arr[i][j] == ']') {
        if (small.empty()) {
          small.push(1);
          break;
        } else {
          char last = small.top();
          if (last == '[') {
            small.pop();
          } else {
            break;
          }
        }
      } else if (arr[i][j] == '(') {
        small.push('(');
      } else if (arr[i][j] == ')') {
        if (small.empty()) {
          small.push(1);
          break;
        } else {
          char last = small.top();
          if (last == '(') {
            small.pop();
          } else {
            break;
          }
        }
      }
    }
    if (!small.empty()) {
      cout << "no" << endl;
    } else {
      cout << "yes" << endl;
    }
    // 큐 둘다 비어있으면 yes
  }
}