#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int parent[300003];
int visit[300003];
vector<int> v;

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
  cin >> N;
  for (int i = 1; i <= N; i++) parent[i] = i;
  for (int i = 0; i < N - 2; i++) {
    int from, to;
    cin >> from >> to;
    Union(from, to);
  }
  for (int i = 1; i <= N; i++) {
    int a = Find(i);
    visit[a] = 1;
  }
  for (int i = 1; i <= N; i++) {
    if (visit[i] == 1) {
      v.push_back(i);
    }
    if (v.size() == 2) {
      for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
      }
      return 0;
    }
  }

  return 0;
}