#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Edge {
  int cost;
  int to;
  bool operator<(Edge right) const { return cost > right.cost; }
};
int cntNode, cntEdge;
int startNode;
priority_queue<Edge> pq;
vector<Edge> v[20002];
int dist[20002];

void dijkstra(int st) {
  for (int i = 1; i <= cntNode; i++) dist[i] = 1e9;
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
      int nextCost = nextEdge.cost;
      int next = nextEdge.to;

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
  cin >> startNode;
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
  }
  dijkstra(startNode);

  for (int i = 1; i <= cntNode; i++) {
    if (dist[i] == 1e9) {
      cout << "INF" << "\n";
    } else {
      cout << dist[i] << "\n";
    }
  }
  return 0;
}