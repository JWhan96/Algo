#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int N;
  stack<int> stk;
  cin >> N;
  string str;
  int num;
  int i = 0;
  while (i < N) {
    cin >> str;
    if (str == "push") {
      cin >> num;
      stk.push(num);
      i++;
      continue;
    }

    if (str == "top") {
      if (stk.size() == 0) {
        cout << "-1" << "\n";
      } else {
        cout << stk.top() << "\n";
      }
      i++;
      continue;
    }

    if (str == "pop") {
      if (stk.size() == 0) {
        cout << "-1" << "\n";
      } else {
        cout << stk.top() << "\n";
        stk.pop();
      }
      i++;
      continue;
    }

    if (str == "size") {
      cout << stk.size() << "\n";
      i++;
      continue;
    }

    if (str == "empty") {
      if (stk.size() == 0) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
      i++;
      continue;
    }
  }
  return 0;
}