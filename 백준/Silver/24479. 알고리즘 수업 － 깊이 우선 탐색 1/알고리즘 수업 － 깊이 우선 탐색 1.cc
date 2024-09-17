#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;
typedef long long ll;

int cntNode, cntEdge;
int st;
vector<int> v[100005];
int visit[100005];
int cnt = 1; // 탐색 순서를 기록하기 위한 카운터

void dfs(int st) {
  visit[st] = cnt++; // 현재 노드를 방문 순서로 기록
  for (int i = 0; i < v[st].size(); i++) {
    int to = v[st][i];
    if (visit[to] != 0) continue; // 아직 방문하지 않았다면
    dfs(to);
    
  }
  return;
}

int main() {
  fastio;
  cin >> cntNode >> cntEdge >> st;
  
  // 간선 입력받기
  for (int i = 0; i < cntEdge; i++) {
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
    v[to].push_back(from); // 양방향 그래프
  }
  
  // 각 노드의 인접 리스트를 오름차순으로 정렬
  for (int i = 1; i <= cntNode; i++) {
    sort(v[i].begin(), v[i].end());
  }

  // DFS 시작
  dfs(st);
  
  // 각 노드의 방문 순서 출력
  for (int i = 1; i <= cntNode; i++) {
    cout << visit[i] << endl;
  }

  return 0;
}