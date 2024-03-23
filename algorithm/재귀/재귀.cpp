#include <iostream>

using namespace std;

// void func(int n) {
//   // 2. 재귀 종료 조건
//   if (n == 10) {
//     return;
//   }
//   // 다음 박스로 가기 전 작업
//   cout << n;
//   // 1. 재귀 기본 구조
//   func(n + 1);
//   // 다음박스로 갔다 돌아오면 작업
//   cout << n;
// }

// int main() {
//   int n;
//   cin >> n;
//   func(n);
//   return 0;
// }
// int n;
// int DAT[10000];
// // index : 박스 번호, value : 해당 박스에서 뽑은 눈

// void func(int now) {
//   if (now == n) {
//     return;
//   }
//   for (int i = 1; i <= 6; i++) {
//     func(now + 1);
//     cout << i;
//   }
//   cout << endl;
// }

// int main() {
//   cin >> n;
//   func(0);
//   return 0;
// }

int N;
int DAT[10000];
// index : 박스 번호, value : 해당 박스에서 뽑은 눈

void func(int now) {
  // 2. 끝낼 조건(기저 조건)
  if (now == N) {  // 0~N-1번 박스에서 숫자들을 다 뽑았으면
    for (int i = 0; i < N; i++) {
      cout << DAT[i] << " ";
    }
    cout << endl;
    return;
  }

  // 1. 재귀 기본 구조
  for (int i = 1; i <= 6; i++) {
    // i : 주사위 눈

    DAT[now] = i;  // now번 박스에서 i라는 눈을 뽑았다.

    func(now + 1);
  }
}

int main() {
  cin >> N;
  func(0);

  return 0;
}