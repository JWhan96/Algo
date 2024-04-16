#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int arr[100001];
int brr[100001];
int start, endd, mid;
bool flag;
int max_arr;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    max_arr = max(arr[i], max_arr);
  }

  sort(arr, arr + n);
  cin >> m;
  for (int j = 0; j < m; j++) {
    cin >> brr[j];
    if (brr[j] > max_arr) {
      cout << 0 << '\n';
      continue;
    }
    start = 0;
    endd = n - 1;
    flag = 0;
    while (start <= endd) {
      flag = 0;
      mid = (start + endd) / 2;
      if (arr[mid] == brr[j]) {
        cout << 1 << '\n';
        flag = 1;
        break;
      } else if (arr[mid] > brr[j]) {
        endd = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    if (!flag) {
      cout << 0 << "\n";
    }
  }

  return 0;
}