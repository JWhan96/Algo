#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int goal;
  cin >> n >> goal;
  vector<int> index(n, 0);
  vector<int> arr(100001, 0);
  for (int i = 0; i < n; ++i) {
    cin >> index[i];
    // cout << index[i]<< endl;
    arr[index[i]]++;
  }

  int count = 0;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      sum = index[i] + index[j];
      if (sum >= goal || (goal - sum) > 100000) {
        continue;
      }
      if (arr[(goal - sum)] == 1 && (goal - sum) != index[i] &&
          (goal - sum) != index[j]) {
        count++;
      }
    }
  }
  cout << count / 3;
  return 0;
}