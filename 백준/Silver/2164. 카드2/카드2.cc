#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int n;
deque<int> dq;
bool flag;
int result;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
  }

  while (!dq.empty()) {
    int s = dq.size();
    if (s == 1) {
      result = dq[0];
    }
    if (!flag) {
      dq.pop_front();
      flag = true;
    } else {
      int a = dq.front();
      dq.pop_front();
      dq.push_back(a);
      flag = false;
    }
  }
  cout << result;
}