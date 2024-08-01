#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cin.tie(0);

using namespace std;

int N;
vector<int> arr;

int main() {
  fastio;

  cin >> N;
  for (int n = 0; n < N; n++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }
  vector<int> arr2 = arr;
  sort(arr2.begin(), arr2.end(), greater<int>());

  if (arr2 == arr) {
    cout << -1;
    return 0;
  }
  int cnt = 0;
  do {
    if (cnt == 1) {
      for (int ar : arr) {
        cout << ar << " ";
      }
      cout << endl;
      return 0;
    }
    cnt++;
  } while (next_permutation(arr.begin(), arr.end()));
}