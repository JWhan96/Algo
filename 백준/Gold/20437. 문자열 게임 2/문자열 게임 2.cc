#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int T;

int main() {
  fastio;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    string s;
    int k;
    cin >> s >> k;

    vector<int> pos[200];  // 각 문자의 위치들을 저장

    for (int i = 0; i < s.size(); i++) {
      pos[s[i]].push_back(i);
    }

    int maxLen = 0;
    int minLen = INT_MAX;

    for (int i = 0; i < 200; i++) {
      if (pos[i].size() >= k) {
        for (int j = 0; j <= pos[i].size() - k; j++) {
          int length = pos[i][j + k - 1] - pos[i][j] + 1;
          minLen = min(minLen, length);
          maxLen = max(maxLen, length);
        }
      }
    }

    if (maxLen == 0 && minLen == INT_MAX) {
      cout << -1 << endl;
    } else {
      cout << minLen << " " << maxLen << endl;
    }
  }
}
