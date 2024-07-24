#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define endl '\n'

using namespace std;

struct Node {
  long long num;
  int idx;
  bool operator<(Node right) const { return num > right.num; }
};
int N;
priority_queue<Node> pq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  vector<int> v(N);

  for (int i = 0; i < N; i++) {
    long long num;
    cin >> num;
    pq.push({num, i});
  }
  int cnt = 0 - 1;
  long long prev = -1e10;
  while (!pq.empty()) {
    Node nowNode = pq.top();
    pq.pop();
    long long nowNum = nowNode.num;
    int nowidx = nowNode.idx;
    if (prev != nowNum) {
      cnt++;
    }
    v[nowidx] = cnt;
    prev = nowNum;
  }
  for (int i = 0; i < N; i++) {
    cout << v[i] << " ";
  }
}
