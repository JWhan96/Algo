#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> item_weights;  // 정점 가중치
const int INF = 1e9;  // 무한대를 의미하는 값 (적당히 큰 값으로 설정)

void floydWarshall(vector<vector<int>>& dist, int n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] != INF && dist[k][j] != INF) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
}

int main() {
  int n, r, m;  // 정점의 수, 탐색 범위, 간선의 수
  cin >> n >> r >> m;

  // 정점 가중치 입력
  item_weights.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> item_weights[i];
  }

  // 그래프의 인접 행렬 초기화
  vector<vector<int>> dist(n, vector<int>(n, INF));

  // 자기 자신으로의 거리는 0으로 초기화
  for (int i = 0; i < n; ++i) {
    dist[i][i] = 0;
  }

  // 간선의 정보를 입력받기
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;  // 1-기반 인덱스를 0-기반 인덱스로 변환
    v--;  // 1-기반 인덱스를 0-기반 인덱스로 변환
    dist[u][v] = w;
    dist[v][u] = w;  // 양방향 간선
  }

  // 플로이드-워셜 알고리즘 수행
  floydWarshall(dist, n);

  // 최대 가중치 합 계산
  int max_sum = 0;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      if (dist[i][j] <= r) {  // 탐색 범위 이내의 정점만 고려
        sum += item_weights[j];
      }
    }
    max_sum = max(max_sum, sum);
  }

  cout << max_sum;
  return 0;
}
