#include <iostream>

using namespace std;

// N과 K를 입력
// N개의 정수
// N개의 정수 중 K개를 이용해서 합 한 값들
// 4 2
// 1 2 3 4
// 입력
// int n, k;
// int arr[1000] = {0};
// int path[1000] = {0};  // <- index : 번째, value : 해당 번째에 뽑은 수
// int result = 0;
// 뽑아가면서 계산하는 방법

// 1. 매개변수 활용하는 법
// void func(int now, int sum) {
//   // now번째 수를 뽑겠다.
//   // sum : 이전까지 내가 뽑은 수들을 합한 값
//   if (now == k) {
//     for (int i = 0; i < k; i++) {  // 0~K-1번까지는 뽑기, K번부터는 뽑으면
//     X(끝)
//       cout << path[i] << " ";
//       // result += path[i];
//     }
//     cout << endl;
//     cout << sum << endl;
//     return;
//   }
//   for (int i = 0; i < n; i++) {
//     // now번째 arr[i]수를 뽑았다.
//     path[now] = arr[i];
//     func(now + 1, sum + arr[i]);
//   }
//   // result = 0;
// }
// int main() {
//   cin >> n >> k;
//   for (int i = 0; i < n; i++) {
//     cin >> arr[i];
//   }
//   func(0, 0);
//   return 0;
// }

// 2. 전역변수 활용하는 법
// void func(int now) {
//   // now번째 수를 뽑겠다.
//   // 2. 기저 조건
//   if (now == k) {
//     // for (int i = 0; i < k; i++) {
//     //   cout << path[i] << " ";
//     // }
//     // cout << endl;
//     cout << result << endl;
//     return;
//   }
//   for (int i = 0; i < n; i++) {
//     // 3. 기록 및 계산(처리)
//     path[now] = arr[i];
//     result += arr[i];
//     // 1. 재귀 기본 구조
//     func(now + 1);
//     // 4. 기록 및 계산(처리)을 복구
//     // arr[i]를 뽑은 상태에서 now+1 이후의 모든 방법 이후
//     // now번째에서 이제 다른 선택을 할 차례 (스택 느낌)
//     result -= arr[i];  // arr[i]를 선택했던걸 삭제(복구)
//     path[now] = 0;     // 배열도 다시 0으로 초기화
//   }
// }
// int main() {
//   cin >> n >> k;
//   for (int i = 0; i < n; i++) {
//     cin >> arr[i];
//   }
//   func(0);
//   return 0;
// }

// 조건을 처리하는 방법
// 1. 뽑고나서 검증
// 2. 뽑으면서 판별 <- 시간효율이 훨씬 좋음
// 인접한 수로 1차이 나는 수는 뽑을 수 없는 경우
// int DAT[1000] = {0};
// void func(int now) {
//   if (now == k) {
//     for (int i = 0; i < k; i++) {
//       cout << path[i] << " ";
//     }
//     cout << endl;
//     return;
//   }
//   for (int i = 0; i < n; i++) {
//     // 뽑기전에 검증 작업 <- 시간 효율을 비약적으로 향상시킴
//     // backtracking(가지치기)
//     if (now != 0 &&  // 첫 선택은 제외
//         (path[now - 1] - arr[i] == 1 || path[now - 1] - arr[i] == -1)) {
//       continue;
//     }
//     if (DAT[arr[i]] == 1) {
//       continue;
//     }
//     path[now] = arr[i];
//     DAT[arr[i]] = 1;
//     func(now + 1);
//     path[now] = 0;
//     DAT[arr[i]] = 0;
//   }
// }
// int main() {
//   cin >> n >> k;
//   for (int i = 0; i < n; i++) {
//     cin >> arr[i];
//   }
//   func(0);
//   return 0;
// }

// 주사위 눈 6가지
// N을 입력받기
// N개의 주사위 눈 조합으로 나올 수 있는 case출력
int n;
int path[1000] = {0};
int DAT[10] = {0};
void func(int now) {
  // 기저조건
  if (now >= n) {
    for (int i = 0; i < n; i++) {
      cout << path[i] << " ";
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= 6; i++) {
    // backtracking
    if ((DAT[i] == 1)) {
      continue;
    }
    // 처리
    path[now] = i;
    DAT[i] = 1;
    // 재귀 시작
    func(now + 1);
    // 처리 복구
    path[now] = 0;
    DAT[i] = 0;
  }
}
int main() {
  cin >> n;
  func(0);
  return 0;
}