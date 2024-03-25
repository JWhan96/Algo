#include <iostream>
#include <vector>

using namespace std;
int cntNode;
int cntEdge;
vector<int> v[101];
int arr[101];
int visited[101];
int cnt = 0;
void func(int now) {
  for (int i = 0; i < v[now].size(); i++) {
    int next = v[now][i];
    if (visited[next] == 1) {
      continue;
    }
    arr[next] = 1;
    visited[next] = 1;
    // cout << next << " ";
    func(next);
    // visited[next] = 0;
  }
}
int main() {
  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
    v[to].push_back(from);
  }
  arr[1] = 1;
  visited[1] = 1;
  func(1);
  for (int i = 0; i < 101; i++) {
    if (arr[i] == 1) {
      cnt++;
    }
  }
  cout << cnt - 1;
}