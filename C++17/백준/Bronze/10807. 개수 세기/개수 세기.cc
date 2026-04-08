#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  int arrP[101] = {};
  int arrM[101] = {};

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (num < 0) {
      arrM[-num]++;
    } else {
      arrP[num]++;
    }
  }
  int v;
  cin >> v;
  if (v < 0) {
    cout << arrM[-v];
  } else {
    cout << arrP[v];
  }

  return 0;
}