#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
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
  
  vector<vector<char>> result;
  for (int i = 1; i < (1 << cnt); i++) {
    vector<char> cop = v;
    vector<int> toRemove;

    for (int j = 0; j < div[i].size(); j++) {
      toRemove.push_back(arr[div[i][j]][0]); // 여는 괄호
      toRemove.push_back(arr[div[i][j]][1]); // 닫는 괄호
    }

    sort(toRemove.rbegin(), toRemove.rend()); // 내림차순으로 정렬

    for (int idx : toRemove) {
      cop.erase(cop.begin() + idx);
    }

    result.push_back(cop);
  }

  sort(result.begin(), result.end());
  result.erase(unique(result.begin(), result.end()), result.end());

  for (auto a : result) {
    for (int i = 0; i < a.size(); i++) {
      cout << a[i];
    }
    cout << endl;
  }

  return 0;
}
