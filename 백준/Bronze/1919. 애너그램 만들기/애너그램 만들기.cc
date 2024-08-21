#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

string a, b;
int aCnt, bCnt;
int dat[300];
int datB[300];
int main() {
  fastio;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 0; i < a.size(); i++) {
    dat[a[i]]++;
    cnt++;
  }
  for (int i = 0; i < b.size(); i++) {
    if (dat[b[i]] == 0) {
      cnt++;
    } else {
      dat[b[i]]--;
      cnt--;
    }
  }

  cout << cnt;
}
