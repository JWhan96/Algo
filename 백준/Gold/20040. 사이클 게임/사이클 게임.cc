#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int parent[500005];
int N, M;

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

  vector<int> v(N);

  for (int i = 0; i <= N; i++) {
    parent[i] = i;
  }
  int cnt = 1;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    if (Find(a) == Find(b)) {
      cout << cnt;
      break;
    }
    Union(a, b);
    cnt++;
  }

  if (cnt > M) {
    cout << 0;
  }

  return 0;
}
