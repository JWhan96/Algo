#include <algorithm>
#include <iostream>
#include <string>

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
    int dat[200] = {
        0,
    };
    string s;
    int num;
    cin >> s >> num;

    for (int i = 0; i < s.size(); i++) {
      dat[s[i]]++;
    }
    int maxCnt = 0;
    int minCnt = 1e9;
    for (int i = 0; i < s.size(); i++) {
      int compCnt = num;
      if (dat[s[i]] >= num) {  // 적어도 그 개수만큼은 있어야 시작
        int cnt = 0;
        char comp = s[i];

        for (int j = i; j < s.size(); j++) {
          cnt++;
          if (s[j] == comp) {
            compCnt--;
            if (compCnt == 0) {
              // dat[s[i]]--;
              if (cnt > maxCnt) {
                maxCnt = cnt;
              }
              if (cnt < minCnt) {
                minCnt = cnt;
              }

              break;
            }
          }
        }
      }
    }
    if (maxCnt == 0 && minCnt == 1e9) {
      cout << -1 << endl;
    } else {
      cout << minCnt << " " << maxCnt << endl;
    }
  }
}