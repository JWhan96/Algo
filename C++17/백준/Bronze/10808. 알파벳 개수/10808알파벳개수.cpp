#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin >> str;
  // a = 97, z = 122
  // 알파벳 개수 26개
  // str = baekjoon
  vector<int> arr(30);
  for (int i = 0; i < str.size(); i++) {
    char inputstr;
    inputstr = str[i];
    int num = inputstr - 97;
    arr[num]++;
  }
  for (int j = 0; j < 26; j++) {
    cout << arr[j] << " ";
  }

  return 0;
}