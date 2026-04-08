#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int arr[26] = {};
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
      cout << "Impossible" << "\n";
      continue;
    }

    for (auto c : a) {
      arr[c - 'a']++;
    }
    bool res = true;
    for (auto d : b) {
      if (arr[d - 'a'] == 0) {
        cout << "Impossible" << "\n";
        res = false;
        break;
      } else {
        arr[d - 'a']--;
      }
    }

    if (res) {
      cout << "Possible" << "\n";
    }
  }
}