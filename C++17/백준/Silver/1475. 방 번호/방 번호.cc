#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int roomNum;
  cin >> roomNum;

  vector<int> arr(10, 1);
  int cnt = 1;
  int a;
  while (roomNum > 0) {
    a = roomNum % 10;  // 각 자리수
    if (a == 6 || a == 9) {
      // 6확인 0일때 9도 확인
      // 둘다 0이면 cnt++ 후 arr 1로 초기화
      if (arr[6] > 0) {
        arr[6]--;
      } else if (arr[9] > 0) {
        arr[9]--;
      } else {
        cnt++;
        for (int i = 0; i < 10; i++) {
          arr[i]++;
        }
        arr[6]--;
      }
    } else {
      // 0인 경우 cnt++ 후 arr 1로 초기화
      if (arr[a] > 0) {
        arr[a]--;
      } else {
        cnt++;
        for (int i = 0; i < 10; i++) {
          arr[i]++;
        }
        arr[a]--;
      }
    }

    roomNum /= 10;
  }

  cout << cnt;

  return 0;
}