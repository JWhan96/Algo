#include <iostream>
#include <vector>

using namespace std;
/*
6 5
1 2
1 3
2 4
3 5
5 6
*/
// 그래프를 저장하는 방법

// 1. 인접행렬 -> 노드개수가 대략 1000, 그리고 간선개수가 많을 때 사용
// 장점 : 특정 간선 정보 찾기
// 모든 node간의 관계를 전부 표현
// 단점 : 메모리 낭비
// int main() {
//   int arr[7][7] = {0};
//   int cntNode, cntEdge;
// cin >> cntNode >> cntEdge;
// for (int i = 0; i < cntEdge; i++) {
//   int from, to;
//   cin >> from >> to;
//   arr[from][to] = 1;
// }
//   // 특정 node에서 연결되어 있는 node찾기
//   int node = 1;
//   for (int to = 1; to <= cntNode; to++) {
//     // cout << arr[node][to] << " " << endl;
//     if (arr[node][to] == 1) {
//       cout << to << " ";
//     }
//   }
//   return 0;
// }

// 2. 인접리스트 -> 노드개수가 1000~10만대, 즉 노드개수가 많을 때 사용
// 장점 : 메모리 낭비X, 필요한 만큼만 메모리 소비
// 단점 : 특정 간선에 대한 정보를 찾기 힘들다
// from -> to, from에 대해서만 정리
// 갈 수 없는 것에 대한 정보가 따로 X
int main() {
  vector<int> v[7];  // v[from] : from번 째 vector
  int cntNode, cntEdge;
  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
    // from 번째 vector에 to정보를 추가(from에 to도 갈 수 있다고 추가)
  }
  int node = 1;
  for (int i = 0; i < v[node].size(); i++) {
    cout << v[node][i] << " ";
  }
}
