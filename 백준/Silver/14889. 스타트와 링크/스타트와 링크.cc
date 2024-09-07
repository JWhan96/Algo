#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

int N;

int main() {
  fastio;
  cin >> N;
  vector<vector<int>> arr(N, vector<int>(N, 0));
  vector<int> idx;
  int cnt = N / 2;
  for (int i = 0; i < N; i++) {
    idx.push_back(i);
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }
  vector<bool> check(N);

  // 팀 구성의 첫 번째 사람을 무조건 A팀에 포함
  fill(check.begin(), check.begin() + cnt, true);
  int mindiff = 1e9;
  do {
    if (!check[0]) break; // 첫 번째 인덱스가 A팀에 있지 않으면 더 이상 볼 필요 없음

    int a = 0;
    int b = 0;
    vector<int> teamA(N);
    for (int i = 0; i < N; i++) {
      if (check[i]) {
        teamA[i] = 1;
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (teamA[i] && teamA[j]) {
          a += arr[i][j];
        } else if (!teamA[i] && !teamA[j]) {
          b += arr[i][j];
        }
      }
    }

    int diff = abs(a - b);
    if (diff < mindiff) {
      mindiff = diff;
    }

  } while (prev_permutation(check.begin(), check.end()));

  cout << mindiff;
}
