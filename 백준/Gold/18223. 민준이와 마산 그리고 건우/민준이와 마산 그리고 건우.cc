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
int cntNode, cntEdge, goal;
vector<Node> v[5005];

vector<int> daikstra(int start) {
  vector<int> dist(cntNode + 1, 1e9);
  priority_queue<Node> pq;
  // for (int i = 0; i <= cntNode; i++) {
  //   dist[i] = 1e9;
  // }
  pq.push({0, start});
  dist[start] = 0;
  while (!pq.empty()) {
    Node nowNode = pq.top();
    pq.pop();
    int now = nowNode.to;
    int nowCost = nowNode.cost;
    if (nowCost > dist[now]) continue;
    for (int i = 0; i < v[now].size(); i++) {
      Node nextNode = v[now][i];
      int next = nextNode.to;
      int nextCost = nextNode.cost;
      if (dist[next] <= dist[now] + nextCost) continue;
      dist[next] = dist[now] + nextCost;
      pq.push({dist[next], next});
    }
  }
  return dist;
}

int main() {
  fastio;
  cin >> cntNode >> cntEdge >> goal;
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
    v[to].push_back({cost, from});
  }
  vector<int> daik1 = daikstra(1);
  vector<int> daikGoal = daikstra(goal);
  int basicCost = daik1[cntNode];
  int totalCost = daikGoal[1] + daikGoal[cntNode];
  if (basicCost == totalCost) {
    cout << "SAVE HIM" << endl;
  } else {
    cout << "GOOD BYE" << endl;
  }
  return 0;
}
