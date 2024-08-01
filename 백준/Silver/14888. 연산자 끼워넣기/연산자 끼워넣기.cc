#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int N;
vector<int> numArr;

int Operate(int a, int b, char op) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      return 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int n = 0; n < N; n++) {
    int num;
    cin >> num;
    numArr.push_back(num);
  }
  int add, sub, mul, div;
  cin >> add >> sub >> mul >> div;
  vector<char> oper;
  oper.insert(oper.end(), add, '+');
  oper.insert(oper.end(), sub, '-');
  oper.insert(oper.end(), mul, '*');
  oper.insert(oper.end(), div, '/');
  sort(oper.begin(), oper.end());
  int i = 0;
  int minValue = INT_MAX;
  int maxValue = INT_MIN;
  do {
    int result = numArr[0];
    for (int i = 1; i < N; i++) {
      result = Operate(result, numArr[i], oper[i - 1]);  // *+ +*
      // cout << i << ": " << result << " " << endl;
    }

    if (result < minValue) {
      minValue = result;
    }
    if (result > maxValue) {
      maxValue = result;
    }

  } while (next_permutation(oper.begin(), oper.end()));

  cout << maxValue << endl;
  cout << minValue << endl;
  return 0;
}