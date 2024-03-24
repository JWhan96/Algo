#include <iostream>
#include <vector>

using namespace std;

vector<int> v[101];
int visited[101] = {0};
int DAT[101] = {0};
int cnt = 0;
void func(int now) {
  for (int i = 0; i < v[now].size(); i++) {
    int next = v[now][i];
    if (visited[next] == 1) {
      continue;
    }
    DAT[next] = 1;
    visited[next] = 1;
    func(next);
    visited[next] = 0;
  }
}
int main() {
  int cntNode, cntEdge;
  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int from, to;
    cin >> from >> to;
    v[to].push_back(from);
    v[from].push_back(to);
  }
  DAT[1] = 1;
  visited[1] = 1;
  func(1);
  for (int i = 0; i < 101; i++) {
    if (DAT[i] == 1) {
      cnt++;
    }
  }
  cout << cnt - 1;
  return 0;
}