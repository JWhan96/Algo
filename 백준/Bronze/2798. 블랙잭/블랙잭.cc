#include <iostream>

using namespace std;
int n, m;
int max_sum;
int dis;
int result_dis = 300001;
int result;
int arr[101];
void dd(int a, int cnt) {
  if (result == m) {
    return;
  }
  if (cnt == 3) {
    if (max_sum > m) {
      return;
    }
    dis = abs(m - max_sum);
    if (result_dis > dis) {
      result_dis = dis;
      result = max_sum;
      return;
    }
    return;
  }
  for (int i = a; i < n; i++) {
    max_sum += arr[i];
    dd(i + 1, cnt + 1);
    max_sum -= arr[i];
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    max_sum += arr[i];
    dd(i + 1, 1);
    if (result == m) {
      cout << result;
      return 0;
    }
    max_sum -= arr[i];
  }
  cout << result;
  return 0;
}