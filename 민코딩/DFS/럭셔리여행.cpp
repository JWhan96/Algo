#include <iostream>
#include <vector>

using namespace std;
int cntNode;
int v[101][101];
int startNode, endNode;
int minCost = 0x7fffffff;
int maxCost = 0;
int cost;
int visited[101];
void func(int now) {
  if (now == endNode) {
    maxCost = max(maxCost, cost);
    minCost = min(minCost, cost);
    return;
  }
  for (int i = 0; i < cntNode; i++) {
    if (v[now][i] == 0) continue;
    if (visited[i] == 1) continue;
    visited[i] = 1;
    cost += v[now][i];
    func(i);
    visited[i] = 0;
    cost -= v[now][i];
  }
}
int main() {
  cin >> cntNode;
  for (int i = 0; i < cntNode; i++) {
    for (int j = 0; j < cntNode; j++) {
      cin >> v[i][j];
    }
  }
  cin >> startNode >> endNode;
  visited[startNode] = 1;
  func(startNode);
  cout << minCost << endl;
  cout << maxCost << endl;
}