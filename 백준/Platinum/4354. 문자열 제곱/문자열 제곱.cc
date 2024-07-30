#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define endl '\n'

using namespace std;

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

// int KMP(const string& text, const string& pattern, int maxR) {
//   int n = text.length();
//   int m = pattern.length();
//   vector<int> table = makeKMP(pattern);
//   int i = 0;
//   int j = 0;
//   int cnt = 0;
//   int maxCnt = 0;
//   while (i < n) {
//     if (pattern[j] == text[i]) {
//       i++;
//       j++;
//     }
//     if (j == m) {
//       cnt++;
//       if (maxCnt < cnt) {
//         maxCnt = cnt;
//       }
//       if (maxR > cnt + (n - i) / m) {
//         return 0;
//       }
//       j = 0;
//     } else if (i < n && text[i] != pattern[j]) {
//       if (j == 0) {
//         cnt = 0;
//         i++;
//       } else {
//         j = 0;
//         cnt = 0;
//       }
//     }
//   }
//   return maxCnt;
// }

int main() {
  string inpText, word1;
  while (true) {
    int maxR = 0;
    cin >> inpText;

    if (inpText == ".") {
      break;
    }
    int n = inpText.length();
    vector<int> table = makeKMP(inpText);
    if (n % (n - (table[table.size() - 1]))) {
      cout << 1 << endl;
    } else {
      cout << n / (n - (table[table.size() - 1])) << endl;
    }
  }
  return 0;
}