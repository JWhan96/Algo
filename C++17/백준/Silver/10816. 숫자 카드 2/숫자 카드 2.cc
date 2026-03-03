#include <iostream>
#include <vector>

#define endl "\n"
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N;
  vector<int> plusVec(10000001, 0);
  vector<int> minusVec(10000001, 0);
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (num >= 0) {
      plusVec[num]++;
    } else {
      minusVec[-num]++;
    }
  }
  cin >> M;
  for (int j = 0; j < M; j++) {
    int num;
    cin >> num;
    if (num >= 0) {
      cout << plusVec[num];
    } else {
      cout << minusVec[-num];
    }
    if (j != (M - 1)) {
      cout << " ";
    }
  }
  return 0;
}