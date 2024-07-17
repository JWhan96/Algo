#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int from;
  int to;
  int cost;
  bool operator<(const Edge& right) const {
    return cost > right.cost;
  }
};

int cntL, cntS;
priority_queue<Edge> pq;
int ladder[101];
int snake[101];
int dist[101];
int dr[] = {1, 2, 3, 4, 5, 6};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> cntL >> cntS;
  for (int i = 0; i < cntL; i++) {
    int from, to;
    cin >> from >> to;
    ladder[from] = to;
  }
  for (int i = 0; i < cntS; i++) {
    int from, to;
    cin >> from >> to;
    snake[from] = to;
  }

  for (int i = 1; i <= 100; i++) dist[i] = 1e9;
  dist[1] = 0;

  pq.push({1, 1, 0});

  while (!pq.empty()) {
    Edge nowEdge = pq.top();
    pq.pop();
    int now = nowEdge.to;
    int nowCost = nowEdge.cost;

    if (now == 100) {
      cout << nowCost << '\n';
      return 0;
    }

    for (int i = 0; i < 6; i++) {
      int next = now + dr[i];
      if (next > 100) continue;

      if (ladder[next] != 0) next = ladder[next];
      if (snake[next] != 0) next = snake[next];

      if (dist[next] > nowCost + 1) {
        dist[next] = nowCost + 1;
        pq.push({now, next, nowCost + 1});
      }
    }
  }

  return 0;
}
