#include <algorithm>
#include <cmath>
#include <iomanip>  // 추가된 라이브러리
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  double cost;
  int to;
  bool operator<(Edge right) const {
    if (cost < right.cost) return false;
    if (cost > right.cost) return true;
    if (to < right.to) return false;
    if (to > right.to) return true;
    return false;
  }
};
struct Node {
  int row;
  int col;
};
int cntNode, cntEdge;
priority_queue<Edge> pq;
vector<Edge> v[1005];
double sum;
vector<Node> arr;
int visit[1005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntNode; i++) {
    int row, col;
    cin >> row >> col;
    arr.push_back({row, col});
  }
  for (int i = 0; i < arr.size(); i++) {
    // 인덱스는 i+1
    for (int j = i + 1; j < arr.size(); j++) {
      double cost;
      int rowR, colR;
      rowR = arr[i].row - arr[j].row;
      colR = arr[i].col - arr[j].col;
      cost = sqrt(pow(rowR, 2) + pow(colR, 2));
      v[i + 1].push_back({cost, j + 1});
      v[j + 1].push_back({cost, i + 1});
      // cout << cost << " ";
    }
  }
  for (int j = 0; j < cntEdge; j++) {
    int st, ed;
    cin >> st >> ed;
    for (int i = 0; i < v[st].size(); ++i) {
      if (v[st][i].to == ed) {
        v[st].erase(v[st].begin() + i);
        break;  // 요소를 제거했으므로 인덱스를 조정하여 반복자 위치를 유지
      }
    }
    for (int k = 0; k < v[ed].size(); ++k) {
      if (v[ed][k].to == st) {
        v[ed].erase(v[ed].begin() + k);
        break;  // 요소를 제거했으므로 인덱스를 조정하여 반복자 위치를 유지
      }
    }
    v[st].push_back({0, ed});
    v[ed].push_back({0, st});
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
    double nowCost = nowEdge.cost;
    if (visit[now] != 0) continue;
    visit[now] = 1;
    sum += nowCost;
    for (int i = 0; i < v[now].size(); i++) {
      Edge nextEdge = v[now][i];
      int next = nextEdge.to;
      double nextCost = nextEdge.cost;
      if (visit[next] != 0) continue;
      pq.push(nextEdge);
    }
  }

  cout << fixed << setprecision(2) << sum << endl;

  return 0;
}