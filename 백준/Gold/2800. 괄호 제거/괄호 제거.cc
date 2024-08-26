#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <set>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

vector<char> v;
string inp;
stack<pair<char, int>> s;
vector<int> arr[12];

int main() {
  fastio;
  cin >> inp;
  int cnt = 0;

  for (int i = 0; i < inp.size(); i++) {
    v.push_back(inp[i]);
    if (inp[i] == '(') {
      cnt++;
      s.push({'(', cnt});
      arr[cnt].push_back(i);
    } else if (inp[i] == ')') {
      int idx = s.top().second;
      s.pop();
      arr[idx].push_back(i);
    }
  }
  vector<int> idxarr;
  for (int i = 1; i <= cnt; i++) {
    idxarr.push_back(i);
  }
  vector<vector<int>> div;
  for (int i = 0; i < (1 << cnt); i++) {
    vector<int> a;
    for (int j = 0; j < cnt; j++) {
      if (i & (1 << j)) {
        a.push_back(idxarr[j]);
      }
    }
    div.push_back(a);
  }

  // result를 set으로 변경
  set<vector<char>> result;
  for (int i = 1; i < (1 << cnt); i++) {
    vector<char> cop = v;
    vector<int> eraseidx;
    for (int j = 0; j < div[i].size(); j++) {
      eraseidx.push_back(arr[div[i][j]][0]);
      eraseidx.push_back(arr[div[i][j]][1]);
    }
    sort(eraseidx.rbegin(), eraseidx.rend());
    for (int j = 0; j < eraseidx.size(); j++) {
      cop.erase(cop.begin() + eraseidx[j]);
    }

    result.insert(cop); // set에 삽입
  }

  // set에 저장된 결과를 출력
  for (const auto& a : result) {
    for (char c : a) {
      cout << c;
    }
    cout << endl;
  }
}
