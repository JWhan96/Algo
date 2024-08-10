#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;
int N, M;
set<vector<int>> s;
int main() {
  fastio;
  cin >> N >> M;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  // nums 정렬
  sort(nums.begin(), nums.end());

  vector<bool> select(N, false);
  fill(select.begin(), select.begin() + M, true);

  do {
    vector<int> combination;
    for (int i = 0; i < N; i++) {
      if (select[i]) {
        combination.push_back(nums[i]);
      }
    }

    do {
      // for (int num : combination) {
      //   cout << num << " ";
      // }
      // cout << endl;
      s.insert(combination);
    } while (next_permutation(combination.begin(), combination.end()));

  } while (prev_permutation(select.begin(), select.end()));

  for (vector<int> v : s) {
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
