#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int cost;
  int to;
  bool operator<(Edge right) const { return cost > right.cost; }
};
int cntNode, cntEdge;
int startBus, endBus;
vector<int> stopv;
vector<Edge> v[1003];
priority_queue<Edge> pq;
int dist[1003];
int from[1003];

void dijkstra(int st) {
  for (int i = 1; i <= cntNode; i++) {
    dist[i] = 1e9;
    // from[i] = -1;
  }
  pq.push({0, st});
  dist[st] = 0;

  while (!pq.empty()) {
    Edge nowEdge = pq.top();
    pq.pop();
    int now = nowEdge.to;
    int nowCost = nowEdge.cost;
    if (dist[now] < nowCost) continue;

    for (int i = 0; i < v[now].size(); i++) {
      Edge nextEdge = v[now][i];
      int next = nextEdge.to;
      int nextCost = nextEdge.cost;

      if (dist[next] <= dist[now] + nextCost) continue;
      // stopv.push_back(next);
      dist[next] = dist[now] + nextCost;
      from[next] = now;
      pq.push({dist[next], next});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
  }
  cin >> startBus >> endBus;
  dijkstra(startBus);

  // for (int at = endBus; at != -1; at = from[at]) {
  //   stopv.push_back(at);
  // }
  // reverse(stopv.begin(), stopv.end());

  int at = endBus;
  while (at != 0) {
    stopv.push_back(at);
    at = from[at];
  }
  reverse(stopv.begin(), stopv.end());

  cout << dist[endBus] << "\n";
  // 어떤벡터의 사이즈
  // 그 벡터 순서대로 출력
  // 그럼 언제 이 벡터에 추가를 하면 좋을 것인가
  cout << stopv.size() << "\n";
  for (int i = 0; i < stopv.size(); i++) {
    cout << stopv[i] << " ";  // 경로 출력
  }

  return 0;
}