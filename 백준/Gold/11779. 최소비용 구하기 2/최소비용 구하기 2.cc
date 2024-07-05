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
    from[i] = -1;  // Initialize from array to -1
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

      if (dist[next] > dist[now] + nextCost) {
        dist[next] = dist[now] + nextCost;
        from[next] = now;
        pq.push({dist[next], next});
      }
    }
  }
}

void getPath(int end) {
  vector<int> path;
  for (int at = end; at != -1; at = from[at]) {
    path.push_back(at);
  }
  reverse(path.begin(), path.end());
  stopv = path;
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
  getPath(endBus);

  cout << dist[endBus] << "\n";  // 최소 비용 출력
  cout << stopv.size() << "\n";  // 경로 길이 출력
  for (int i = 0; i < stopv.size(); i++) {
    cout << stopv[i] << " ";  // 경로 출력
  }
  return 0;
}
