#include <iostream>
#include <sstream>
#include <stack>
#define endl '\n'

using namespace std;

pair<string, int> p;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 3; i++) {
    string a;
    cin >> a;
    if (a == "Fizz" || a == "Buzz" || a == "FizzBuzz") continue;
    p = {a, i};
    break;
  }
  string inp = p.first;
  int num;
  int idx = p.second;
  stringstream ss(inp);
  ss >> num;
  for (int i = idx; i < 4; i++) {
    num++;
  }

  if (num % 3 == 0 && num % 5 == 0) {
    cout << "FizzBuzz";
  } else if (num % 3 == 0 && num % 5 != 0) {
    cout << "Fizz";
  } else if (num % 3 != 0 && num % 5 == 0) {
    cout << "Buzz";
  } else if (num % 3 != 0 && num % 5 != 0) {
    cout << num;
  }
}