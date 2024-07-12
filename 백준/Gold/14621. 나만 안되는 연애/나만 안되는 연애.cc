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
vector<Edge> v[10005];
int visit[10005];
int sum;
int cntNode, cntEdge;
char arr[1005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> cntNode >> cntEdge;
  for (int i = 1; i <= cntNode; i++) {
    char a;
    cin >> a;
    arr[i] = a;
  }
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    if (arr[from] == arr[to]) continue;
    v[from].push_back({cost, to});
    v[to].push_back({cost, from});
  }
  int st = 1;
  visit[st] = 1;
  for (int i = 0; i < v[st].size(); i++) {
    if (arr[st] == arr[v[st][i].to]) continue;
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
      if (arr[now] == arr[next]) continue;
      pq.push(nextEdge);
    }
  }
  int result = sum;
  for (int i = 1; i <= cntNode; i++) {
    if (visit[i] == 0) {
      result = -1;
    }
  }
  cout << result;
  return 0;
}