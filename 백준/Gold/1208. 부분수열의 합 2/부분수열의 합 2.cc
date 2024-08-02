#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
using namespace std;
map<int, int> total;
int N, S;
long long result;
int main() {
  fastio;
  cin >> N >> S;
  int idx = N / 2;
  vector<int> arr1(idx);
  if (N % 2 != 0) {
    idx = (N / 2) + 1;
  }
  vector<int> arr2(idx);
  int half = N / 2;
  int totalSum = 0;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (i < half) {
      arr1[i] = num;
    } else {
      arr2[i - half] = num;
    }
    // if (num == S) {
    //   result++;
    // }
    totalSum += num;
  }
  int idx1 = arr1.size();
  int idx2 = arr2.size();

  for (int i = 0; i < (1 << idx1); i++) {  // 1<<n은 2^n 따라서 부분집합의 개수
    int sum1 = 0;
    for (int j = 0; j < idx1; j++)  // 원소의 개수만큼 for문 돌아감
      if (i & (1 << j)) {  // i&(1<<j) i의 j번째 bit가 1인지 아닌지를 확인함
        sum1 += arr1[j];
      }
    total[sum1]++;
    // cout << endl;
  }
  for (int i = 0; i < (1 << idx2); i++) {  // 1<<n은 2^n 따라서 부분집합의 개수
    int sum2 = 0;
    for (int j = 0; j < idx2; j++)  // 원소의 개수만큼 for문 돌아감
      if (i & (1 << j))  // i&(1<<j) i의 j번째 bit가 1인지 아닌지를 확인함
        sum2 += arr2[j];
    result += total[S - sum2];
  }
  if (S == 0) {
    cout << result - 1;
  } else {
    cout << result;
  }

  return 0;
}