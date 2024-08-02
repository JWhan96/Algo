#include <iostream>
#include <set>
#include <vector>
using namespace std;
int N;
int result[2000005];
int main() {
  cin >> N;
  vector<int> arr(N);
  // set<int> result;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < (1 << N); i++) {  // 1<<n은 2^n 따라서 부분집합의 개수
    int sum = 0;
    for (int j = 0; j < N; j++) {  // 원소의 개수만큼 for문 돌아감
      if (i & (1 << j)) {  // i&(1<<j) i의 j번째 bit가 1인지 아닌지를 확인함
        sum += arr[j];
      }
    }
    // result.insert(sum);
    result[sum] = 1;
    // cout << sum << " ";
  }
  // int idx = 1;
  // while (result.find(idx) != result.end()) {
  //   idx++;
  // }
  int r = 0;
  for (int idx = 1; idx < 2000005; idx++) {
    if (result[idx] == 0) {
      r = idx;
      break;
    }
  }
  cout << r;

  return 0;
}
