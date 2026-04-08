#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // N: 학생수, K :한방 최대 인원, 0여, 1남
  int N, K;
  cin >> N >> K;

  // 성별, 학년
  int arr[2][7] = {};
  for (int i = 0; i < N; i++) {
    int sex, grade;
    cin >> sex >> grade;
    arr[sex][grade]++;
  }

  int cnt = 0;
  for (int i = 1; i < 7; i++) {
    if ((arr[0][i] % K) == 0) {
      cnt += arr[0][i] / K;
    } else if ((arr[0][i] % K) != 0) {
      cnt += (arr[0][i] / K) + 1;
    }

    if ((arr[1][i] % K) == 0) {
      cnt += (arr[1][i] / K);
    } else if ((arr[1][i] % K) != 0) {
      cnt += (arr[1][i] / K) + 1;
    }
  }

  cout << cnt;

  return 0;
}