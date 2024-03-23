#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  int N, M;
  int black_num = 0;
  int in_black = 0;
  int in_common = 0;
  int black_name[100001] = {
      0,
  };
  cin >> n >> m;
  vector<vector<int>> apart(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> apart[i][j];
    }
  }
  cin >> N >> M;
  vector<vector<int>> black(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> black[i][j];
      black_name[black[i][j]] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (black_name[apart[i][j]] == 1) {
        in_black++;
      } else {
        in_common++;
      }
    }
  }
  cout << in_black << endl << in_common;

  return 0;
}