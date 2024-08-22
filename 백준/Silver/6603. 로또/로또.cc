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

int T;

int main() {
  fastio;
  string inp = "";
  int N = 0;
  while (true) {
    cin >> N;
    if (N == 0) return 0;
    getline(cin, inp);

    vector<int> v;
    string a = "";
    for (int i = 0; i < inp.size(); i++) {
      if (inp[i] == ' ') {
        if (!a.empty()) {  // 공백이 연속으로 나올 경우 처리
          int b = stoi(a);
          v.push_back(b);
          a = "";
        }
      } else {
        a += inp[i];
      }
    }
    if (!a.empty()) {
      int b = stoi(a);
      v.push_back(b);
    }

    int M = v.size();
    vector<bool> select1(N, false);
    vector<bool> select2(M, false);
    fill(select1.begin(), select1.begin() + M, true);
    fill(select2.begin(), select2.begin() + 6, true);

    do {
      vector<int> comb;
      for (int i = 0; i < N; i++) {
        if (select1[i]) {
          comb.push_back(v[i]);
          // cout << v[i] << " ";
        }
      }
      do {
        for (int j = 0; j < M; j++) {
          if (select2[j]) {
            cout << comb[j] << " ";
          }
        }
        cout << endl;
      } while (prev_permutation(select2.begin(), select2.end()));

      // cout << endl;
    } while (prev_permutation(select1.begin(), select1.end()));
    cout << endl;
  }
}