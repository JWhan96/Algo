#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int cntNode, cntEdge;
vector<int> arr[1001];
int visited[1001];
int cnt;

void dfs(int now) {
  for (int i = 0; i < arr[now].size(); i++) {
    int next = arr[now][i];
    if (visited[next] == 1) {
      continue;
    }
    visited[next] = 1;
    dfs(next);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int from, to;
    cin >> from >> to;
    arr[from].push_back(to);
    arr[to].push_back(from);
  }

  for (int i = 1; i < cntNode + 1; i++) {
    if (visited[i] == 0) {
      visited[i] = 1;
      dfs(i);
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}