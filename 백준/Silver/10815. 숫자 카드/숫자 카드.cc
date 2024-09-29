#include <iostream>
#include <unordered_set>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;
unordered_set<int> us;

int main() {
  fastio;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    us.insert(num);
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int res;
    cin >> res;
    if (us.find(res) != us.end()) {
      cout << 1 << " ";
    } else {
      cout << 0 << " ";
    }
  }
}
