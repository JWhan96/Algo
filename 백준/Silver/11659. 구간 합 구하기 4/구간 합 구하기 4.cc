#include <iostream>
#define endl '\n'

using namespace std;

int N, M;
long long arr[100005];
long long result;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    arr[i] = arr[i - 1] + a;
  }
  for (int i = 0; i < M; i++) {
    result = 0;
    int s, e;
    cin >> s >> e;
    result = arr[e] - arr[s - 1];
    cout << result << endl;
  }
  return 0;
}