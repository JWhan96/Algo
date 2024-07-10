// spanning tree : 신장트리
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