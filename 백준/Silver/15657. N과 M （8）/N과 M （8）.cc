#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

int N, M;

void generateCombinationsWithRepetition(vector<int>& nums,
                                        vector<int>& combination, int start,
                                        int depth, int N, int M) {
  if (depth == M) {
    for (int num : combination) {
      cout << num << " ";
    }
    cout << endl;
    return;
  }

  for (int i = start; i < N; i++) {
    combination.push_back(nums[i]);
    generateCombinationsWithRepetition(nums, combination, i, depth + 1, N,
                                       M);  // i를 다시 사용하여 중복 허용
    combination.pop_back();                 // 백트래킹
  }
}

int main() {
  fastio;
  int N, M;
  vector<int> nums;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    nums.push_back(num);
  }

  sort(nums.begin(), nums.end());

  vector<int> combination;
  generateCombinationsWithRepetition(nums, combination, 0, 0, N, M);

  return 0;
}