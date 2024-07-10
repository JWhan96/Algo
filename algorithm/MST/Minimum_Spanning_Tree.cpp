// spanning tree : 신장트리

// Minimum Spanning Tree
// └ Kruskal
//   - 선을 기반('모든 선을 전부 한번에 알고 있어야함')
//   - 코드가 좀 더 심플
//   - 시간 복잡도 : ElogV
// └ Prim
//   - 점을 기반('점이 점차 퍼져나가는 모양')
//   - 코드가 좀 더 복잡
//   - 시간 복잡도 : ElogV

// 정점: 9개 , 최소 간선 수(모든 정점을 잇는) : 8(9-1)개
// minimum spanning tree : 최소 신장 트리는 최소 간선수의 가중치의 합이 최소가
// 되도록
// => Kruskal algorithm(크루스칼 알고리즘)
// 설계
// 1. 그래프 정보 <- 인접행렬, 인접리스트 X
//   => sturct Edge{
//     int cost;
//     int A, B
//   }
// 2. Edge를 정렬
// 3. Edge를 순서대로 연결
//   조건: 이미 연결(그룹화)된 경우는 연결 X
//

/*
9 13
1 2 23
2 3 17
2 5 31
3 4 27
3 8 10
4 8 7777
1 6 10
5 6 0
5 7 12
6 7 56
7 8 9
8 9 59
5 3 56
*/

/*
선을 기준으로 가중치의 합 구하는 방법
Kruskal Algorithm
1. Edge를 저장
2. Edge를 정렬
3. Edge를 순서대로 연결
  -> 이미 연결된 점끼린 연결 X

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Edge {
  int cost;
  int A, B;
  bool operator<(Edge right) {
    if (cost < right.cost) return true;
    if (cost > right.cost) return false;

    if (A < right.A) return true;
    if (A > right.A) return false;

    if (B < right.B) return true;
    if (B > right.B) return false;
    return false;
  }
};
Edge edges[20];
int parent[20];
int sum;

// 번외 2. 파인드함수
int Find(int A) {
  if (A == parent[A]) return A;
  int rootA = Find(parent[A]);
  parent[A] = rootA;
  return rootA;
}

// 번외 3. 유니온함수
void Union(int A, int B) {
  int rootA = Find(A);
  int rootB = Find(B);
  if (rootA == rootB) return;
  parent[rootB] = rootA;
}

int main() {
  int cntNode, cntEdge;
  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int A, B, cost;
    cin >> A >> B >> cost;
    edges[i] = {cost, A, B};
  }  // 1. Edge 저장

  // 2. Edge 정렬
  sort(edges, edges + cntEdge);

  // 번외 1. parent 초기화
  for (int i = 1; i <= cntNode; i++) {
    parent[i] = i;
  }

  // 3. Edge 연결 <- Union-Find
  for (int i = 0; i < cntEdge; i++) {
    Edge now = edges[i];
    // 이미 같은 그룹(연결)이면 무시
    if (Find(now.A) == Find(now.B)) continue;

    Union(now.A, now.B);
    sum += now.cost;
  }
  cout << sum;
}
*/

/*
점을 기준으로 가중치의 합을 구하는 방법
Prim 알고리즘
BFS처럼 하나의 점에서 점차 '퍼져나가는 형태'
  -> BFS는 발견된 순서대로 퍼져나감
  -> Prim은 작은 가중치 순서대로 퍼져나감
  -> dijkstra '시작점부터의 거리' 순서대로
  -> Prim은 그 점(now) 기준에서부터 거리 순서대로

BFS순서
1. 그래프 저장
2. queue 생성
3. 시작점 세팅
4. now 꺼내기
5. now -> next 찾기
6. next추가
7. 4~6단계 반복

설계
1. 그래프 저장() A, B, cost
  -> 인접행렬, 인접리스트
2. **Priority_queue 생성**
3. 시작점 세팅('아무 점')
4. now 꺼내기(cost가 가장 작게 갈수 있는 점)
5. now-> next 찾기(now는 합쳐짐, 그 now에서 갈 수 있는 새로운 점 찾기)
6. next를 priority_queue에 추가
*/
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
struct Edge {
  int cost;
  int to;
  bool operator<(Edge right) const {
    if (cost < right.cost) return false;
    if (cost > right.cost) return true;
    if (to < right.to) return false;
    if (to > right.to) return true;
    return false;
  }
};

int main() {
  vector<Edge> v[20];  // v[from] <- from에서 갈 수 있는 (cost로)'점'

  int cntNode, cntEdge;
  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int A, B, cost;
    cin >> A >> B >> cost;
    v[A].push_back({cost, B});
    v[B].push_back({cost, A});
  }  // 1. 그래프 저장

  // 2. priority queue 생성
  priority_queue<Edge> pq;  // <- 후보지들 저장({cost, node 번호})
  int visited[20] = {
      0,
  };  // 확정 여부

  // 3. 시작점 세팅
  int st = 5;
  visited[st] = 1;
  for (int i = 0; i < v[st].size(); i++) {
    Edge edge = v[st][i];  // 시작점에 연결된 선들 싹다 찾기
    pq.push(edge);         // 해당 선을 기반으로 후보지 등록
  }
  int sum = 0;  // 총 비용
  // 7. 4~6단계 반복 <- O(ElogE) == O(ElogV)
  while (!pq.empty()) {
    // 4. now 꺼내기(now가 확정)
    Edge now = pq.top();
    pq.pop();
    int nowNode = now.to;
    if (visited[nowNode]) continue;  // 확정됐던 점이면 무시
    // 확정되지 않았던 점만
    visited[nowNode] = 1;  // 확정 기록
    sum += now.cost;

    // 5. next(후보지) 찾기
    for (int i = 0; i < v[nowNode].size(); i++) {
      Edge nextEdge = v[nowNode][i];

      // 6. next를 pq에 추가
      pq.push(nextEdge);
    }
  }
  cout << sum;
}