#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int cntNode, cntEdge, startNode;
queue<int> q;
vector<int> arr[100001];
int visited[100001];
int cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  scanf("%d %d %d", &cntNode, &cntEdge, &startNode);
  for (int i = 0; i < cntEdge; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    arr[from].push_back(to);
    arr[to].push_back(from);
  }
  for (int i = 1; i <= cntNode; i++) {
    sort(arr[i].begin(), arr[i].end());
  }
  cnt++;
  q.push(startNode);
  visited[startNode] = cnt;

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < arr[now].size(); i++) {
      int next = arr[now][i];
      if (visited[next] != 0) {
        continue;
      }
      cnt++;
      q.push(next);
      visited[next] = cnt;
    }
  }
  for (int i = 1; i <= cntNode; i++) {
    printf("%d\n", visited[i]);
  }
  return 0;
}
