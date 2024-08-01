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
  for (int n = 1; n <= N; n++) {
    arr.push_back(n);
  }
  // vector<int> arr2 = arr;
  // sort(arr2.begin(), arr2.end());

  do {
    for (int ar : arr) {
      cout << ar << " ";
    }
    cout << endl;

  } while (next_permutation(arr.begin(), arr.end()));
}