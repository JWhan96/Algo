#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int main() {
  fastio;
  int N;
  cin >> N;
  vector<int> pos;  // 양수 저장
  vector<int> neg;  // 음수 저장
  int ones = 0;     // 1의 개수 저장
  int zeros = 0;    // 0의 개수 저장
  int result = 0;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (num > 1)
      pos.push_back(num);
    else if (num < 0)
      neg.push_back(num);
    else if (num == 1)
      ones++;
    else
      zeros++;
  }

  // 양수 처리
  sort(pos.begin(), pos.end(), greater<int>());
  for (int i = 0; i + 1 < pos.size(); i += 2) {
    result += pos[i] * pos[i + 1];
  }
  if (pos.size() % 2 == 1) {
    result += pos.back();
  }

  // 음수 처리
  sort(neg.begin(), neg.end());

  for (int i = 0; i + 1 < neg.size(); i += 2) {
    result += neg[i] * neg[i + 1];
  }
  if (neg.size() % 2 == 1 && zeros == 0) {
    result += neg.back();
  }

  // 1의 개수 더하기
  result += ones;

  cout << result << endl;

  return 0;
}