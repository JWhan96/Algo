#include <iostream>
using namespace std;
// 필요한 구조
int parent[10];

// int Find(int A) { // 해주고 싶은 역할? : A가 속한 그룹(대표찾기)
//     if (A == parent[A]) // 어디서 끝???? : '대표'는 어떻게??? == 자기자신이
//     부모
//         return A;
//     // A의 부모로가서 마저 찾아와!!!
//     int rootA = Find(parent[A]); // Find(parent[A]) : 위로 대표 물어보기
//     parent[A] = rootA; // 대표를 알았으니 direct로 저장
//     return rootA; // 위로 물어본 결과를 밑으로 반환
// }
//
// void Union(int A, int B) { // 해주고 싶은 역할? : A가 속한 그룹과 B가 속한
// 그룹 합치기
//     // 1. 가장 먼저?
//     int rootA = Find(A);
//     int rootB = Find(B);
//
//     // 2. 합치기!!!
//     parent[rootB] = rootA; //<- rootB를 rootA밑으로! (문제의 조건에 맞게
//     설정)
// }

// 그룹 data관리 : 그룹에 몇 명이 있는지 관리
//   -> 해당 그룹의 data는 '모두' '대표'에게
int cnt[10];  // index : 그룹 번호, value : 해당 그룹에 속한 인원 수
int Find(int A) {
  if (A == parent[A]) return A;
  return parent[A] = Find(parent[A]);
}

void Union(int A, int B) {
  int rootA = Find(A);
  int rootB = Find(B);

  if (rootA == rootB) return;  // 같은 그룹내의 점끼리는 무시

  parent[rootB] = rootA;     // A밑으로 B가 들어옴
  cnt[rootA] += cnt[rootB];  // A그룹에 B의 인원이 전부 들어옴
  cnt[rootB] = 0;            // B의 인원수 0으로 초기화
}

int main() {
  // 1. parent 세팅(각자가 대표다, 전부 1인 기업)
  for (int i = 0; i < 10; i++) {
    parent[i] = i;
    cnt[i] = 1;
  }

  int cntNode;
  int cntQuery;
  cin >> cntNode >> cntQuery;
  for (int i = 0; i < cntQuery; i++) {
    int A, B;
    cin >> A >> B;

    Union(A, B);
  }

  for (int i = 1; i <= cntNode; i++) cout << i << " : " << Find(i) << "\n";
  int de = 1;
}