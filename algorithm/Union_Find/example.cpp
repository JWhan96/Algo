/*
6 4
1 2
3 4
5 6
2 4
*/
#include <iostream>

using namespace std;

int parent[10];  // 대표 찾는 배열
int cnt[10];  // index: 그룹번호, value: 해당 그룹에 속한 인원수
int Find(int A) {  // 가장 위의 대표 찾기
  if (parent[A] == A) {
    return A;
  }
  int rootA = Find(parent[A]);  // 재귀 구조
  parent[A] = rootA;            // 대표를 다 알아냈으니 대표저장
  return rootA;
}

void Union(int A, int B) {
  int rootA = Find(A);
  int rootB = Find(B);

  if (rootA == rootB) return;

  parent[rootB] = rootA;
  cnt[rootA] += cnt[rootB];
  cnt[rootB] = 0;
}

int main() {
  for (int i = 0; i < 10; i++) {
    parent[i] = i;
    cnt[i] = 1;
  }
  int cntNode, cntQuery;
  cin >> cntNode >> cntQuery;
  for (int i = 0; i < cntQuery; i++) {
    int A, B;
    cin >> A >> B;
    Union(A, B);
  }

  for (int i = 1; i <= cntNode; i++) {
    cout << parent[i] << " ";
  }
  cout << endl;
  // 처음에는 바로 위 대표만 저장댐
  for (int i = 1; i <= cntNode; i++) {
    int result = Find(i);
    cout << result << " ";
  }
  cout << endl;
  // 한번은 모두 검색을 한 이후에 가장 위 대표로 저장댐
  for (int i = 1; i <= cntNode; i++) {
    cout << "rootcnt:" << cnt[i] << " ";
  }
  cout << endl;

  return 0;
}