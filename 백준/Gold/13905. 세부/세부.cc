#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int cost;
  int to;
  bool operator<(Edge right) const {
    if (cost > right.cost) return false;
    if (cost < right.cost) return true;
    if (to < right.to) return true;
    if (to > right.to) return false;
    return false;
  }
};
priority_queue<Edge> pq;
vector<Edge> v[100005];
int cntNode, cntEdge;
int stNode, endNode;
int result = 1e9;
int visit[100005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> cntNode >> cntEdge;
  cin >> stNode >> endNode;
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
    v[to].push_back({cost, from});
  }

  visit[stNode] = 1;
  for (int i = 0; i < v[stNode].size(); i++) {
    Edge nextEdge = v[stNode][i];
    pq.push(nextEdge);
  }
  int sum = 0;
  while (!pq.empty()) {
    Edge nowEdge = pq.top();
    pq.pop();
    int now = nowEdge.to;
    int nowCost = nowEdge.cost;
    // if (visit[now] != 0) continue;
    visit[now] = 1;
    sum += nowCost;
    if (nowCost < result) result = nowCost;
    if (now == endNode) {
      cout << result;
      return 0;
    }
    for (int i = 0; i < v[now].size(); i++) {
      Edge nextEdge = v[now][i];
      if (visit[nextEdge.to] != 0) continue;
      pq.push(nextEdge);
    }
  }
  // cout << result;
  cout << sum;
  return 0;
}  // 1765