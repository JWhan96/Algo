#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int parent[100005];

int Find(int A) {
  if (parent[A] == A) {
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
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Scenario " << i << ":" << '\n';
    int N;
    cin >> N;
    for (int i = 0; i <= N; i++) {
      parent[i] = i;
    }
    int numF;
    cin >> numF;
    for (int i = 0; i < numF; i++) {
      int A, B;
      cin >> A >> B;
      Union(A, B);
    }
    int rel;
    cin >> rel;
    for (int i = 0; i < rel; i++) {
      int A, B;
      cin >> A >> B;
      int rootA, rootB;
      rootA = Find(A);
      rootB = Find(B);
      if (rootA == rootB) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
    cout << '\n';
  }
}