#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100];
int visited[1000];
int cntNode, cntEdge;

void preorder(int now) {
  for (int i = v[now].size() - 1; i >= 0; i--) {
    int next = v[now][i];
    if (visited[next] == 1) {
      continue;
    }
    visited[next] = 1;
    cout << next << " ";
    preorder(next);
    // visited[next] = 0;
  }
}
void postorder(int now) {
  for (int i = v[now].size() - 1; i >= 0; i--) {
    int next = v[now][i];
    if (visited[next] == 1) {
      continue;
    }
    visited[next] = 1;
    postorder(next);
    cout << next << " ";
    // visited[next] = 0;
  }
}

int main() {
  cin >> cntNode >> cntEdge;
  int startNode;
  cin >> startNode;
  int from, to;
  for (int i = 0; i < cntEdge; i++) {
    cin >> from >> to;
    v[from].push_back(to);
  }
  for (int i = 1; i <= cntNode; i++) {
    sort(v[i].begin(), v[i].end());
  }
  int now;
  now = startNode;
  cout << now << " ";
  visited[now] = 1;
  preorder(now);
  cout << endl;
  memset(visited, 0, sizeof(visited));
  visited[now] = 1;
  postorder(now);
  cout << now;
}