#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  long cost;
  int to;
  bool operator<(Edge right) const {
    if (cost < right.cost) return false;
    if (cost > right.cost) return true;
    if (to < right.to) return false;
    if (to > right.cost) return true;
    return false;
  }
};
priority_queue<Edge> pq;
vector<Edge> v[100005];
int visit[100005];
long sum;
long maxCost;
int cntNode, cntEdge;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int from, to;
    long cost;
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
    v[to].push_back({cost, from});
    maxCost += cost;
  }
  int st = 1;
  visit[st] = 1;
  for (int i = 0; i < v[st].size(); i++) {
    pq.push(v[st][i]);
  }

  while (!pq.empty()) {
    Edge nowEdge = pq.top();
    pq.pop();
    int now = nowEdge.to;
    long nowCost = nowEdge.cost;
    if (visit[now] != 0) continue;
    visit[now] = 1;
    sum += nowCost;
    for (int i = 0; i < v[now].size(); i++) {
      Edge nextEdge = v[now][i];
      int next = nextEdge.to;
      long nextCost = nextEdge.cost;
      if (visit[next] != 0) continue;
      pq.push(nextEdge);
    }
  }
  for (int i = 1; i <= cntNode; i++) {
    if (visit[i] == 0) {
      cout << -1;
      return 0;
    }
  }
  cout << maxCost - sum;
  return 0;
}