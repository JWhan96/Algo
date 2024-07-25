#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int M;
string str;

vector<int> buildKMPTable(const string &pattern) {
  int m = pattern.length();
  vector<int> table(m, 0);
  int j = 0;

  for (int i = 1; i < m; i++) {
    if (pattern[i] == pattern[j]) {
      j++;
      table[i] = j;
    } else {
      if (j != 0) {
        j = table[j - 1];
        i--;  // 재검사
      } else {
        table[i] = 0;
      }
    }
  }

  return table;
}

int KMP(const string &text, const string &pattern) {
  int n = text.length();
  int m = pattern.length();
  vector<int> table = buildKMPTable(pattern);
  int i = 0, j = 0;
  int count = 0;

  while (i < n) {
    if (pattern[j] == text[i]) {
      i++;
      j++;
    }

    if (j == m) {
      count++;
      j = table[j - 1];
    } else if (i < n && pattern[j] != text[i]) {
      if (j != 0) {
        j = table[j - 1];
      } else {
        i++;
      }
    }
  }

  return count;
}

int main() {
  cin >> N >> M >> str;
  string word1((N + N + 1), ' ');
  for (int i = 0; i < (N + N + 1); i++) {
    if (i % 2 == 0) {
      word1[i] = 'I';
    } else {
      word1[i] = 'O';
    }
  }

  cout << KMP(str, word1) << endl;

  return 0;
}
