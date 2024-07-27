#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

deque<int> dq;
vector<int> v;
int N;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 1) {
      dq.push_front(i + 1);
    } else if (v[i] == 2) {
      int a = dq.front();
      dq.pop_front();
      dq.push_front(i + 1);
      dq.push_front(a);
    } else if (v[i] == 3) {
      dq.push_back(i + 1);
    }
  }
  while (!dq.empty()) {
    int result = dq.front();
    dq.pop_front();
    cout << result << " ";
  }
}