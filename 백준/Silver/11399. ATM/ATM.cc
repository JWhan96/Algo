#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n;
int result;
int rr;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    result = result + v[i];
    rr += result;
  }
  cout << rr;
  return 0;
}