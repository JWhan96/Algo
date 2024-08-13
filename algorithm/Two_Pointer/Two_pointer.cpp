#include <iostream>
using namespace std;

int main() {
  // int N, K;
  // cin >> N >> K;
  // int arr[100] = {
  //     0,
  // };
  // for (int i = 0; i < N; i++) cin >> arr[i];

  // // two pointer : 2개의 변수로 '구간을 표현'
  // int left = 0;
  // int right = 0;
  // int sum = arr[0];
  // // 초기화
  // while (left < N && right < N) {  // <- 조건은 어떻게 주면 될까요????
  //   if (sum < K) {
  //     right++;  // 구간을 넓히기
  //     sum += arr[right];
  //   } else if (sum > K) {
  //     sum -= arr[left];
  //     left++;  // 구간을 좁히기
  //   } else if (sum == K) {
  //     cout << "O";
  //     return 0;
  //   }
  // }
  // cout << "X";

  /*
  9 102
  23 27 22 77 36 5 6 55 37

  연속한 4개의 합이 102*/
  int N, K;
  cin >> N >> K;
  int arr[10];
  for (int i = 0; i < N; i++) cin >> arr[i];

  int left = 0;
  int right = 0;
  int sum = arr[0];
  while (left < N && right < N) {
    if (right - left + 1 < 4) {  // right - left + 1 : 구간의 개수
      right++;                   // <- data가 부족할 때, 구간을 넓힘
      sum += arr[right];
    } else {
      sum -= arr[left];
      left++;  // <- data가 이미 충분, 구간을 옮겨볼 차례
    }
  }  // <- 반복횟수 : O(N)

  // ex) 연속한 구간에 최대 5가지 종류의 data를 포함 하는 케이스
  //      <- DAT를 활용
  // 1 2 2 1 3 1 2 7 6 6 1 2 7 5 1 3 2 4 6 9 8 7 5
}