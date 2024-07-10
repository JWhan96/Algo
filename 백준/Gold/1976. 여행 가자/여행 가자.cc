#include <iostream>
#include <string>
#include <vector>

using namespace std;

int parent[205];
int cntNode, cntTrip;
vector<int> v;
string result;
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
  cin >> cntNode;
  cin >> cntTrip;
  for (int i = 1; i <= cntNode; i++) {
    parent[i] = i;
  }
  for (int i = 1; i <= cntNode; i++) {
    for (int j = 1; j <= cntNode; j++) {
      int info;
      cin >> info;
      if (info == 0)
        continue;
      else {
        Union(i, j);
      }
    }
  }
  for (int i = 0; i < cntTrip; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  for (int i = 1; i < v.size(); i++) {
    if (Find(v[i - 1]) == Find(v[i])) {
      result = "YES";
    } else {
      cout << "NO";
      return 0;
    }
  }
  cout << result;
  return 0;
}