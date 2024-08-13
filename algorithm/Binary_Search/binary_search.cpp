#include <iostream>
using namespace std;

bool condition(long long num) {
  // num을 검증 <- 가능? 불가능???
  // 1234567890의 제곱근 정수부
  if (num * num >= 1234567890) return true;
  return false;
}

int main() {
  int arr[10] = {7, 10, 14, 15, 56, 57, 64, 77, 99, 2727};

  int K = 13;

  // 기본 binary search
  // binary search를 할 때 '꼭 먼저 처리해줘야 하는 작업' : *정렬*
  // int left = 0;
  // int right = 9;
  // while (left <= right) {  // 구간이 뒤집히기 전까지만
  //   // 정가운데를 가정
  //   int mid = (left + right) / 2;
  //   if (arr[mid] > K) {         // mid보다 작은쪽에 K가 존재
  //     right = mid - 1;          // right을 작은쪽으로 옮겨줌
  //   } else if (arr[mid] < K) {  // mid보다 큰쪽에 K가 존재
  //     left = mid + 1;           // left를 큰쪽으로 옮겨줌
  //   } else if (arr[mid] == K) {
  //     cout << "OK";
  //     break;
  //   }
  // }

  // upper_bound < -특정 수부터 커지는 위치
  // arr에서 K보다 큰 숫자가 어디부터 시작? ? ? ? ? ? ?
  // int left = 0;
  // int right = 9;
  // int ret = 0;  // arr에서 K보다 큰 숫자가 시작되는 지점
  // while (left <= right) {
  //   int mid = (left + right) / 2;
  //   if (arr[mid] <= K) {  // mid보다 큰쪽에 있음
  //     left = mid + 1;
  //   } else if (arr[mid] > K) {  // mid보다 작은 쪽에 있다.
  //     ret = mid;  // K보다 큰 숫자가 발견될때마다 기록
  //     right = mid - 1;
  //   }
  // }
  // = > 최종적으로 K보다 큰 값이 '어디서부터 시작'

  // lower_bound
  // K이상의 수가 시작되는 지점
  // int left = 0;
  // int right = 9;
  // int ret = 0;  // 정답 기록
  // while (left <= right) {
  //   int mid = (left + right) / 2;
  //   if (arr[mid] < K) {
  //     left = mid + 1;
  //   } else if (arr[mid] >= K) {
  //     ret = mid;  // K이상인 지점 발견!!!!
  //     right = mid - 1;
  //   }
  // }
  // => K이상인 지점이 어디부터인가?

  // binary search의 최상위 난도
  // (조건에 따라 최적의 답을 구하는 방식 - parametric search)
  // 범위를 좁히는 것 : 조건에 따라 좁힘
  int left = 0;
  int right = 100000000;
  int ret = 0;
  // 전체 구간에서 특정 원하는 조건에 해당하는 값
  while (left <= right) {
    int mid = (left + right) / 2;
    if (condition(mid)) {
      ret = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
}
