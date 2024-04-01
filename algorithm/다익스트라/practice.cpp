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
  }
};

int cntNode, cntEdge;
vector<Edge> v[10];
int dist[10];

int main() {
  cin >> cntNode >> cntEdge;
  // priority_queue<Edge> pq;
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    v[from].push_back({cost, to}) v[to].push_back({cost, from})
  }
}
