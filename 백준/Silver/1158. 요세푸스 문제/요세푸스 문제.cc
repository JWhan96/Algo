#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;

int prv[5005];
int nxt[5005];

int main() {
  fastio;
  int N, M;
  cin >> N >> M;
  vector<int> v;
  int len = N;
  for (int i = 1; i <= N; i++) {
    prv[i] = (i == 1) ? N : i - 1;
    nxt[i] = (i == N) ? 1 : i + 1;
  }
  int i = 1;
  for (int cur = 1; len != 0; cur = nxt[cur]) {
    if (i == M) {
      nxt[prv[cur]] = nxt[cur];
      prv[nxt[cur]] = prv[cur];
      v.push_back(cur);
      i = 1;
      len--;
    } else
      i++;
  }
  cout << "<";
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i];
    if (i != v.size() - 1) cout << ", ";
  }
  cout << ">";
}
