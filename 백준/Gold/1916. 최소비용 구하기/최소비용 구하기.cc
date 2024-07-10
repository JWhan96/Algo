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

vector<Edge> v[1003];
priority_queue<Edge> pq;
int dist[1003];

void dijkstra(int st) {
  for (int i = 1; i <= cntNode; i++) {
    dist[i] = 1e9;
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

      dist[next] = dist[now] + nextCost;
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

  cout << dist[endBus];

  return 0;
}