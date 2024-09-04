#include <algorithm>
#include <iostream>
#include <vector>
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;
struct Node {
  int day;
  ll pay;
};
int N;
ll dp[1500100];
int main() {
  fastio;
  cin >> N;
  vector<Node> arr(N + 1);

  for (int i = 1; i <= N; i++) {
    int d, p;
    cin >> d >> p;
    arr[i].day = d;
    arr[i].pay = p;
  }
  int maxR = 0;
  for (int i = 1; i <= N; i++) {
    Node now = arr[i];
    int nowD = now.day;
    ll nowP = now.pay;
    // cout << "now " << nowD << " " << nowP << endl;
    dp[i] = max(dp[i], dp[i - 1]);
    if (i + nowD > N + 1) continue;
    dp[i + nowD] = max(dp[i + nowD], dp[i] + nowP);
    if (dp[i + nowD] > maxR) {
      maxR = dp[i + nowD];
    }
  }
  // cout << dp[N + 1];
  cout << maxR;

  return 0;
}
