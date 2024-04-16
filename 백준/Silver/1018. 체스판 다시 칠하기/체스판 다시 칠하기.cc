#include <iostream>
#include <string>

using namespace std;
int result = 1000001;
int n, m;
char arr[51][51];
char brr[51][51];
char crr[51][51];
bool bflag;
bool cflag;
int bcnt, ccnt;
int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      bflag = true;

    } else {
      bflag = false;
    }
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (i < 8 && j < 8) {
        if (bflag && j % 2 == 0) {
          brr[i][j] = 'W';
          crr[i][j] = 'B';
        } else if (bflag && j % 2 != 0) {
          brr[i][j] = 'B';
          crr[i][j] = 'W';
        } else if (!bflag && j % 2 != 0) {
          brr[i][j] = 'W';
          crr[i][j] = 'B';
        } else if (!bflag && j % 2 == 0) {
          brr[i][j] = 'B';
          crr[i][j] = 'W';
        }
      }
    }
  }

  for (int p = 0; p <= n - 8; p++) {
    for (int k = 0; k <= m - 8; k++) {
      int bcnt = 0;  // 8x8 배열마다 새로운 비교 시작
      int ccnt = 0;
      for (int i = p; i < p + 8; i++) {
        for (int j = k; j < k + 8; j++) {
          if (arr[i][j] != brr[i - p][j - k]) {
            bcnt++;
          }
          if (arr[i][j] != crr[i - p][j - k]) {
            ccnt++;
          }
        }
      }
      int localResult = min(bcnt, ccnt);  // 최소값 계산
      result = min(result, localResult);  // 전체 최소값 업데이트
    }
  }

  cout << result;
  return 0;
}
