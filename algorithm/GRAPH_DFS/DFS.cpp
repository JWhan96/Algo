#include <iostream>
#include <vector>

using namespace std;

vector<int> v[7];      // 노드와 간선의 정보 담는 배열
vector<int> path;      // 내가 어느점을 들렀는지 알기위한 배열
int visited[7] = {0};  // 이 노드를 들렀는지 알기 위한 배열
void func(int now) {   // 갈 수 있는 모든 방향을 가므로 DFS
  if (now == 4) {
    for (int i = 0; i < path.size(); i++) {
      cout << path[i] << " ";
    }
    cout << endl;
    return;
  }
  // now에서 갈 수 있는 next
  // 인접행렬
  // for (int next = 1; next <= cntNode; next++) {
  //   if (arr[now][next] == 0) {
  //     continue; // now => next로 갈 수 있는 선이 없으면 무시
  //   }
  // }
  for (int i = 0; i < v[now].size(); i++) {
    int next = v[now][i];
    // 판별
    if (visited[next] == 1) {
      continue;
    }
    path.push_back(next);
    // cout << next << endl;
    visited[next] = 1;
    func(next);
    visited[next] = 0;
    path.pop_back();
  }
}
int main() {
  int cntNode, cntEdge;
  cin >> cntNode >> cntEdge;
  for (int i = 0; i < cntEdge; i++) {
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
  }
  // cout << 1 << endl;
  visited[1] = 1;
  path.push_back(1);
  func(1);
  return 0;
}