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
int goal;
priority_queue<Edge> pq;
vector<Edge> v[1001];
int dist1[1001];  // 자신의 노드(1~N)에서 목표 노드로 가는데 걸리는 cost(모든
                  // 노드로 가는데 걸리는 배열이 저장)
int dist2[1001];  // 목표 노드까지 가는데 걸리는 cost만 저장하는 배열
int dist3[1001];  // 목표노드에서 다시 자기마을로 가는데 걸리는 cost
int maxT;

void dijkstra1(int st) {
  for (int i = 0; i <= cntNode; i++) {
    dist1[i] = 1e9;
  }
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
      if (dist1[next] <= dist1[now] + nextCost) {
        continue;
      }
      dist1[next] = dist1[now] + nextCost;
      pq.push({dist1[next], next});
    }
  }
}

void dijkstra2(int st) {
  for (int i = 0; i <= cntNode; i++) {
    dist3[i] = 1e9;
  }
  pq.push({0, st});
  dist3[st] = 0;
  while (!pq.empty()) {
    Edge nowEdge = pq.top();
    pq.pop();
    int now = nowEdge.to;
    int nowCost = nowEdge.cost;
    if (dist3[now] < nowCost) continue;
    for (int i = 0; i < v[now].size(); i++) {
      Edge nextEdge = v[now][i];
      int next = nextEdge.to;
      int nextCost = nextEdge.cost;
      if (dist3[next] <= dist3[now] + nextCost) {
        continue;
      }
      dist3[next] = dist3[now] + nextCost;
      pq.push({dist3[next], next});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  cin >> cntNode >> cntEdge >> goal;
  for (int i = 0; i < cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
  }

  for (int i = 1; i <= cntNode; i++) {
    int st;
    st = i;
    if (st == goal) {
      dijkstra2(st);
    } else {
      dijkstra1(st);
      dist2[i] = dist1[goal];
      // cout << 3 << " " << dist1[goal] << endl;
    }
  }
  // dist2, 3(갈때 + 돌아올때) 더한 후 가장 오래 걸리는 학생의 소요시간 확인
  for (int i = 1; i <= cntNode; i++) {
    int result;
    result = dist2[i] + dist3[i];
    // cout << 1 << " " << dist2[i] << endl;
    // cout << 2 << " " << i << " " << dist3[i];
    // cout << endl;
    if (maxT < result) {
      maxT = result;
    }
  }
  cout << maxT;

  return 0;
}