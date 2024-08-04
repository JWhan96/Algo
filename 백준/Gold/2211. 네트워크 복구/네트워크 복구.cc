#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

struct Node {
  int cost;
  int to;
  bool operator<(Node right) const { return cost > right.cost; }
};
int cntNode, cntEdge;
vector<Node> v[1005];
int dist[1005];
priority_queue<Node> pq;
vector<pair<int, int>> node;
int Parent[1005];

int main() {
  fastio;
  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
    v[to].push_back({cost, from});
  }
  for (int i = 0; i < 1005; i++) {
    dist[i] = 1e9;
  }
  dist[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    Node nowNode = pq.top();
    pq.pop();
    int nowCost = nowNode.cost;
    int now = nowNode.to;
    if (nowCost > dist[now]) continue;

    for (int i = 0; i < v[now].size(); i++) {
      int next = v[now][i].to;
      int nextCost = v[now][i].cost;

      if (dist[next] <= dist[now] + nextCost) continue;

      dist[next] = dist[now] + nextCost;
      pq.push({dist[next], next});
      Parent[next] = now;  // 부모 노드 저장
    }
  }

  // 복구된 경로의 개수 출력
  cout << cntNode - 1 << endl;

  // 각 복구된 경로의 상세 정보 출력
  for (int i = 2; i <= cntNode; i++) {
    cout << Parent[i] << " " << i << endl;
  }

  return 0;
}
