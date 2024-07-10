#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

int parent[1000001];

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
  for (int i = 0; i <= N; i++) {
    parent[i] = i;
  }
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a;
    if (a == 0) {
      cin >> b >> c;
      Union(b, c);
    } else {
      cin >> b >> c;
      int rootB, rootC;
      rootB = Find(b);
      rootC = Find(c);
      if (rootB == rootC) {
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}