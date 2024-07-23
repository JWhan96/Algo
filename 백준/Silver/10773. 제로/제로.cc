#include <iostream>
#include <stack>
#define endl '\n'

using namespace std;
int N;
int sum;
stack<int> s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int n = 0; n < N; n++) {
    int num;
    cin >> num;

    if (num != 0) {
      s.push(num);
    } else {
      s.pop();
    }
  }
  while (!s.empty()) {
    int a = s.top();
    s.pop();
    sum += a;
  }
  cout << sum;
  return 0;
}