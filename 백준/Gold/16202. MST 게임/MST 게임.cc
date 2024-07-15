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
    if (to > right.to) return true;
    return false;
  }
};
struct pqEdge {
  int cost;
  int to;
  int from;
  bool operator<(pqEdge right) const {
    if (cost < right.cost) return false;
    if (cost > right.cost) return true;
    if (to < right.to) return false;
    if (to > right.to) return true;
    return false;
  }
};
priority_queue<pqEdge> pq;
vector<Edge> v[1005];
vector<Edge> newV[1005];
int visit[1005];
int cntNode, cntEdge, cntTurn;
int score = -1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> cntNode >> cntEdge >> cntTurn;
  for (int i = 1; i <= cntEdge; i++) {
    int from, to, cost;
    cin >> from >> to;
    cost = i;
    v[from].push_back({cost, to});
    v[to].push_back({cost, from});
  }  // 입력 끝

  for (int k = 1; k <= cntTurn; k++) {  // 턴만큼 반복

    if (score == 0) {
      cout << score << " ";
      continue;
    }
    int remFrom;
    int remTo;
    int remCost;
    pqEdge minR;
    int minRR = 1e9;
    // if (k != 1) {
    //   for (int i = 0; i <= cntNode; ++i) {
    //     v[i] = newV[i];
    //   }
    // }
    for (int i = 0; i <= cntNode; i++) {
      visit[i] = 0;
      // newV[i].clear();
    }
    while (!pq.empty()) {
      pq.pop();
    }  // newV와 visit[i], pq초기화
    int sum = 0;

    int st = 1;
    visit[st] = 1;
    for (int i = 0; i < v[st].size(); i++) {
      Edge nextEdge = v[st][i];
      int next = nextEdge.to;
      int nextCost = nextEdge.cost;

      pq.push({nextCost, next, st});
    }
    while (!pq.empty()) {
      pqEdge nowEdge = pq.top();
      pq.pop();
      int now = nowEdge.to;
      int nowCost = nowEdge.cost;
      int st = nowEdge.from;
      if (visit[now] != 0) continue;
      visit[now] = 1;
      // newV[st].push_back({nowCost, now});
      // newV[now].push_back({nowCost, st});
      if (minRR > nowCost) {
        minRR = nowCost;
        minR = {nowCost, now, st};
      }
      sum += nowCost;
      for (int i = 0; i < v[now].size(); i++) {
        Edge nextEdge = v[now][i];
        int next = nextEdge.to;
        int nextCost = nextEdge.cost;
        if (visit[next] != 0) continue;
        pq.push({nextCost, next, now});
      }
    }
    score = sum;
    for (int i = 1; i <= cntNode; i++) {
      if (visit[i] == 0) {
        score = 0;
        break;
      }
    }
    // for (int i = 0; i <= cntNode; i++) {
    //   v[i].clear();
    // }
    remFrom = minR.from;
    remTo = minR.to;
    remCost = minR.cost;

    for (int i = 0; i < v[remFrom].size(); ++i) {
      if (v[remFrom][i].to == remTo) {
        v[remFrom].erase(v[remFrom].begin() + i);
        --i;  // 요소를 제거했으므로 인덱스를 조정하여 반복자 위치를 유지
      }
    }
    for (int i = 0; i < v[remTo].size(); ++i) {
      if (v[remTo][i].to == remFrom) {
        v[remTo].erase(v[remTo].begin() + i);
        --i;  // 요소를 제거했으므로 인덱스를 조정하여 반복자 위치를 유지
      }
    }
    cout << score << " ";
  }

  return 0;
}