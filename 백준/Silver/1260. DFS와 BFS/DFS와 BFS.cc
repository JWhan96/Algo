#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int cntNode, cntEdge, startNode;
vector<int> v[1001];
queue<int> q;
int visit[1001];
void bfs() {
  q.push(startNode);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    cout << now << " ";
    for (int i = 0; i < v[now].size(); i++) {
      int next = v[now][i];
      if (visit[next] == 1) {
        continue;
      }
      q.push(next);
      visit[next] = 1;
    }
  }
}
void dfs(int now) {
  for (int i = 0; i < v[now].size(); i++) {
    int next = v[now][i];
    if (visit[next] == 1) {
      continue;
    }
    cout << next << " ";
    visit[next] = 1;
    dfs(next);
  }
}
int main() {
  cin >> cntNode >> cntEdge >> startNode;
  int from, to;
  for (int i = 0; i < cntEdge; i++) {
    cin >> from >> to;
    v[from].push_back(to);
    v[to].push_back(from);
  }
  for (int i = 1; i <= cntNode; i++) {
    sort(v[i].begin(), v[i].end());
  }
  visit[startNode] = 1;
  cout << startNode << " ";
  dfs(startNode);
  cout << endl;
  memset(visit, 0, sizeof(visit));
  visit[startNode] = 1;
  bfs();
}