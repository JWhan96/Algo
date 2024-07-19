#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'

using namespace std;

int cntW, cntB;
int N;
int arr[130][130];
int visit[130][130];
int resultW, resultB;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      arr[i][j] = a;
    }
  }
  int cutN = N;
  // cout << cutN;
  while (cutN != 0) {
    for (int i = 0; i < N; i += cutN) {
      for (int j = 0; j < N; j += cutN) {
        cntB = 0;
        cntW = 0;
        for (int ii = i; ii < i + cutN; ii++) {
          for (int jj = j; jj < j + cutN; jj++) {
            if (visit[ii][jj] != 0) continue;
            if (arr[ii][jj] == 1) cntB++;
            if (arr[ii][jj] == 0) cntW++;
          }
          if (cntB == cutN * cutN) {
            resultB++;
            for (int rr = i; rr < i + cutN; rr++) {
              for (int cc = j; cc < j + cutN; cc++) {
                visit[rr][cc] = 1;
              }
            }
          } else if (cntW == cutN * cutN) {
            resultW++;
            for (int qq = i; qq < i + cutN; qq++) {
              for (int ww = j; ww < j + cutN; ww++) {
                visit[qq][ww] = 1;
              }
            }
          }
        }
      }
    }
    cutN /= 2;
  }
  cout << resultW << endl << resultB;

  return 0;
}