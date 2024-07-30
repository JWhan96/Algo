#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define endl '\n'

using namespace std;
vector<int> findIdx;

vector<int> makeKMP(const string& pattern) {
  int m = pattern.length();
  int j = 0;
  vector<int> table(m, 0);
  for (int i = 1; i < m; i++) {
    if (pattern[i] == pattern[j]) {
      j++;
      table[i] = j;
    } else {
      if (j == 0) {
        table[i] = j;
      } else {
        j = table[j - 1];
        i--;
      }
    }
  }
  return table;
}

int KMP(const string& text, const string& pattern) {
  int n = text.length();
  int m = pattern.length();
  vector<int> table = makeKMP(pattern);
  int i = 0;
  int j = 0;
  int cnt = 0;
  while (i < n) {
    if (pattern[j] == text[i]) {
      i++;
      j++;
    }
    if (j == m) {
      cnt++;
      findIdx.push_back((i - m + 1));
      j = table[j - 1];
    } else if (i < n && text[i] != pattern[j]) {
      if (j == 0) {
        i++;
      } else {
        j = table[j - 1];
      }
    }
  }
  return cnt;
}

int main() {
  string inpText, word1;
  getline(cin, inpText);
  getline(cin, word1);

  int resultCnt = KMP(inpText, word1);
  cout << resultCnt << endl;
  for (int i = 0; i < findIdx.size(); i++) {
    cout << findIdx[i] << " ";
  }
  return 0;
}