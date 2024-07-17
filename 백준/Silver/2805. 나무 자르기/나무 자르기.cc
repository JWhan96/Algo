#include <iostream>
#include <vector>

using namespace std;

long long N, result;
vector<long long> v;

long long maxTree;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> result;
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    v.push_back(a);
    if (a > maxTree) {
      maxTree = a;
    }
  }
  long long startP = 0;
  long long endP = maxTree;
  long long point = 0;
  while (startP <= endP) {
    long long num;
    num = 0;
    point = (endP + startP) / 2;

    for (int i = 0; i < v.size(); i++) {
      long long cut = v[i] - point;
      if (cut <= 0) continue;
      num += cut;
    }
    if (num < result)
      endP = point - 1;
    else
      startP = point + 1;

    if (num == result) {
      cout << point << endl;
      return 0;
    }
  }
  cout << endP << endl;
  return 0;
}