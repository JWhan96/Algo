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
    if (to < right.to) return false;
    if (to > right.cost) return true;
    return false;
  }
};
priority_queue<Edge> pq;
vector<Edge> v[100005];
int visit[100005];
int sum;
int cntNode, cntEdge;
int maxT;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    cin >> cntNode >> cntEdge;
    if (cntNode == 0 && cntEdge == 0) break;
    for (int i = 0; i < cntNode + 1; i++) {
      v[i].clear();
      visit[i] = 0;
    }
    sum = 0;
    maxT = 0;
    for (int i = 0; i < cntEdge; i++) {
      int from, to, cost;
      cin >> from >> to >> cost;
      v[from].push_back({cost, to});
      v[to].push_back({cost, from});
      maxT += cost;
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
      int nowCost = nowEdge.cost;
      if (visit[now] != 0) continue;
      visit[now] = 1;
      sum += nowCost;

      for (int i = 0; i < v[now].size(); i++) {
        Edge nextEdge = v[now][i];
        int next = nextEdge.to;
        int nextCost = nextEdge.cost;
        if (visit[next] != 0) continue;
        pq.push(nextEdge);
      }
    }
    cout << maxT - sum << '\n';
  }
  return 0;
}