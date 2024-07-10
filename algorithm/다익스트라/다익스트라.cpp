#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int cost;
  int to;
  bool operator<(Edge right) const {
    // 거리가 짧은 것 우선
    if (cost < right.cost) return false;  // 내 거리가 더 짧으면 내걸 먼저
    if (cost > right.cost) return true;

    return false;
  }
};

int cntNode, cntEdge;
vector<Edge> v[10];

void dijkstra_1(int st) {
  int dist[10];  // DAT, index : 점 번호, value : 지금까지 계산한 거리
  int isvalid[10] = {
      0,
  };  // DAT, index : 점 번호, value : 해당 점은 거리가 확정인가?
  for (int i = 0; i < 10; i++) dist[i] = 1e9;  // 1 * 10^9
  dist[st] = 0;
  //----세팅----

  for (int i = 0; i < cntNode - 1; i++) {
    int minDist = 1e9;
    int minNode = -1;
    for (int node = 1; node <= cntNode; node++)
      if (isvalid[node] == 0 && minDist > dist[node]) {
        // 확정 X && 거리가 최소
        minDist = dist[node];
        minNode = node;
      }
    // 가장 짧은 거리인 점 1개

    isvalid[minNode] = 1;  // 해당 점을 '확정'

    // 이번에 확정지은 점에서 갈 수 있는 점 찾기
    int now = minNode;
    for (int i = 0; i < v[now].size(); i++) {
      Edge nextEdge = v[now][i];
      int next = v[now][i].to;
      int nextCost = v[now][i].cost;

      // 'now통해 next로 가는 거리'가 이미 알고있던 방법보다 비효율적이면 무시
      if (dist[next] <= dist[now] + nextCost) continue;

      // 'now를 통해 next로 가는 거리'가 현재까지 best
      dist[next] = dist[now] + nextCost;
    }
  }

  for (int i = 1; i <= cntNode; i++) cout << i << " : " << dist[i] << "\n";
}

void dijkstra_2(int st) {
  int dist[10];  // DAT, index : 점 번호, value : 지금까지 계산한 거리
  for (int i = 0; i < 10; i++) dist[i] = 1e9;  // 1 * 10^9
  dist[st] = 0;
  priority_queue<Edge> pq;  // <- 어떤 정보들을 저장? (거리, 노드)
  pq.push({0, st});  // 0의 거리로 st라는 점을 갈 수 있다.(시작점 세팅)
  //----세팅----

  // pq : 시작점에서 갈 수 있는 방법들

  while (!pq.empty()) {  // <- 더 이상 남은 방법이 없으면 끝!
    Edge nowEdge = pq.top();
    pq.pop();  // <= 모든 선의 개수만큼 data를 꺼냄
    int now = nowEdge.to;
    int nowCost = nowEdge.cost;
    // 내가 이미 확정된 점(계산이 완료된 점)을 다시 계산해야 하는 작업을 방지
    if (dist[now] < nowCost)
      // 최소 거리인 dist[now]가 이번에 꺼낸 정보인 nowCost보다 작다
      //      이미 dist[now]에 해당하는 정보로 계산이 완료.
      continue;
    // <- 거리가 최소이면서 처음 계산하는 점 <= 확정 작업

    // 이번에 확정지은 점에서 갈 수 있는 점 찾기 <= '모든 점에서 딱 1번씩'
    for (int i = 0; i < v[now].size(); i++) {  // <= 모든 '선'
      Edge nextEdge = v[now][i];
      int next = v[now][i].to;
      int nextCost = v[now][i].cost;

      // 'now통해 next로 가는 거리'가 이미 알고있던 방법보다 비효율적이면 무시
      if (dist[next] <= dist[now] + nextCost) continue;

      // 'now를 통해 next로 가는 거리'가 현재까지 best
      // now->next로 가는 '새로운 방법'
      dist[next] = dist[now] + nextCost;
      pq.push({dist[next], next});  // <= 최악 : 모든 선을 확인할때마다 pq추가
    }
  }

  // 점의 개수 : V
  // 선의 개수 : E => 최악 : 모든 점들이 서로 연결
  // 시간 복잡도 : 모든 선을 넣고 빼는 시간
  //              ElogE = Elog(V^2) = 2ElogV = ElogV

  for (int i = 1; i <= cntNode; i++) cout << i << " : " << dist[i] << "\n";
}

// dijkstra와 비슷한 알고리즘(이 알고리즘을 잘 익혀두시면 dijkstra하실때
// 편합니다.) BFS와 매우 유사 BFS 문제들은 대체적으로 코드가 비슷비슷하게
// 나옴(BFS코드는 안바꾸고 재활용해도 될정도) Dijkstra도 문제에서 사용할 때
// 코드가 거~~~~~의 그대로 사용할 정도 문제 풀때 어떻게????? => 이전 코드랑
// 비슷하겠다고 그대로 가져다 사용 X
//					    => 항상 백지에서 시작해서 손에
// 익혀가는 과정이 필요
// 왜?????? => 1. 빠르게 작성, 2. *디버깅 연습*

void dijkstra_3(int st) {
  int dist[10];
  for (int i = 0; i < 10; i++) dist[i] = 1e9;
  priority_queue<Edge> pq;  // 2. queue생성 => priority queue생성
  pq.push({0, st});         // 3. 시작점 세팅
  dist[st] = 0;

  // 7. pq가 비워질때까지
  while (!pq.empty()) {
    Edge nowEdge = pq.top();
    pq.pop();  // 4. now꺼내기
    int now = nowEdge.to;
    int nowCost = nowEdge.cost;
    // 저장되어 있는 cost가 지금 cost보다 작으면 continue
    if (dist[now] < nowCost) continue;

    // 5. now->next를 찾기
    for (int i = 0; i < v[now].size(); i++) {
      Edge nextEdge = v[now][i];
      int next = nextEdge.to;
      int nextCost = nextEdge.cost;

      if (dist[next] <= dist[now] + nextCost) continue;

      // 6. next를 pq에 추가
      dist[next] = dist[now] + nextCost;
      pq.push({dist[next], next});
    }
  }

  for (int i = 1; i <= cntNode; i++) cout << i << " : " << dist[i] << "\n";

  /*
  정확한 차이
  BFS
   => queue를 사용 : '찾은 순서대로' 가보기 위해
      -> 적은 개수의 점을 들려 가는 방법

  Dijkstra
   => priority queue를 사용 : '거리가 짧은 순서대로' 가보기 위해
      -> 가장 짧은 거리로 가는 방법


  최단 거리 문제 중 언제는 BFS?, 언제는 Dijkstra?
  1. 적은 개수의 점을 들려 가는 방법????? <- 성립????
  2. 성립 안하면 dijkstra
  */
}

int main() {
  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
    v[to].push_back({cost, from});
  }  // 1. 그래프 구성
  dijkstra_3(1);
}