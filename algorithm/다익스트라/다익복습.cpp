#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int cost;
  int to;

  bool operator<(Edge right) const {
    if (cost < right.cost) return false;
    if (cost > right.cost) return true;
    return false;
  };
};

int cntNode, cntEdge;
vector<Edge> v[10];

void daik(int st) {
  int dist[10];
  for (int i = 0; i < 10; i++) dist[i] = 1e9;
  priority_queue<Edge> pq;
  pq.push({0, st});
  dist[st] = 0;

  while (!pq.empty()) {
    Edge nowEdge = pq.top();
    int now = nowEdge.to;
    int nowCost = nowEdge.cost;
    pq.pop();
    if (dist[now] < nowCost) continue;

    for (int i = 0; i < v[now].size(); i++) {
      int next = v[now][i].to;
      int nextCost = v[now][i].cost;

      if (dist[next] <= dist[now] + nextCost) continue;

      dist[next] = dist[now] + nextCost;
      pq.push({dist[next], next});
    }
  }
  for (int i = 1; i <= cntNode; i++) {
    cout << i << ":" << dist[i] << "\n";
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
    v[to].push_back({cost, from});
  }

  daik(1);

  return 0;
}