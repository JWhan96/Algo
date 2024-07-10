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
vector<Edge> v[805];
priority_queue<Edge> pq;
int dist1[805];
int dist2[805];
int result1 = 1e9, result2 = 1e9, result3 = 1e9;

void dijkstra1(int st) {  // N1에서 출발

  for (int i = 1; i < 805; i++) dist1[i] = 1e9;
  pq.push({0, st});
  dist1[st] = 0;
  while (!pq.empty()) {
    Edge nowEdge = pq.top();
    pq.pop();

    int now = nowEdge.to;
    int nowCost = nowEdge.cost;

    if (dist1[now] < nowCost) continue;

    for (int i = 0; i < v[now].size(); i++) {
      Edge nextEdge = v[now][i];
      int next = nextEdge.to;
      int nextCost = nextEdge.cost;
      if (dist1[next] <= dist1[now] + nextCost) continue;
      dist1[next] = dist1[now] + nextCost;
      pq.push({dist1[next], next});
    }
  }
}

void dijkstra2(int st) {  // N2에서 출발

  for (int i = 1; i < 805; i++) dist2[i] = 1e9;
  pq.push({0, st});
  dist2[st] = 0;
  while (!pq.empty()) {
    Edge nowEdge = pq.top();
    pq.pop();

    int now = nowEdge.to;
    int nowCost = nowEdge.cost;

    if (dist2[now] < nowCost) continue;

    for (int i = 0; i < v[now].size(); i++) {
      Edge nextEdge = v[now][i];
      int next = nextEdge.to;
      int nextCost = nextEdge.cost;
      if (dist2[next] <= dist2[now] + nextCost) continue;
      dist2[next] = dist2[now] + nextCost;
      pq.push({dist2[next], next});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> cntNode >> cntEdge;
  int N = cntNode;
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
    v[to].push_back({cost, from});
  }
  int N1, N2;
  cin >> N1 >> N2;
  dijkstra1(N1);
  dijkstra2(N2);
  // dist1에서 1, N2 + dist2에서 N
  // dist1에서 N + dist2에서 1, N1
  if (dist1[1] == 1e9 || dist1[N2] == 1e9 || dist2[N] == 1e9) {
    result1 = 1e9;
  } else {
    result1 = dist1[1] + dist1[N2] + dist2[N];
  }
  if (dist2[1] == 1e9 || dist2[N1] == 1e9 || dist1[N] == 1e9) {
    result2 = 1e9;
  } else {
    result2 = dist2[1] + dist2[N1] + dist1[N];
  }
  result3 = min(result1, result2);
  if (result3 >= 1e9) {
    cout << -1;
  } else {
    cout << result3;
  }
  return 0;
}