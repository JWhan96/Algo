#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// 대표 번호를 0으로?
int N, M;
int cntT;
int cntP;
int parent[53];
// int visit[6];
vector<int> v[53];
int result;  // 전체 결과값
// int cnt;     // 파티 하나마다 결과값
// int found;

int Find(int A) {
  if (A == parent[A]) {
    return A;
  }
  int rootA = Find(parent[A]);
  parent[A] = rootA;
  return rootA;
}

void Union(int A, int B) {
  int rootA = Find(A);
  int rootB = Find(B);
  if (rootA == rootB) return;
  parent[rootB] = rootA;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  cin >> cntT;

  for (int i = 0; i <= N; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < cntT; i++) {
    int numT;
    cin >> numT;
    Union(0, numT);
  }

  for (int i = 0; i < M; i++) {
    cin >> cntP;

    for (int j = 0; j < cntP; j++) {
      int numP;
      cin >> numP;
      v[i].push_back(numP);
    }
    if (!v[i].empty()) {
      int first_member = v[i][0];
      for (int k = 0; k < v[i].size(); k++) {
        Union(first_member, v[i][k]);
      }
    }
  }

  for (int i = 0; i < M; i++) {
    bool flag = true;
    for (int j = 0; j < v[i].size(); j++) {
      if (Find(v[i][j]) == Find(0)) {
        flag = false;
        break;
      }
    }
    if (flag == true) {
      result++;
    }
  }

  cout << result;

  return 0;
}
