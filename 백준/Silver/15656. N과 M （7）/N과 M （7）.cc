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

void generatePermutationsWithRepetition(vector<int>& nums,
                                        vector<int>& permutation, int depth,
                                        int N, int M) {
  if (depth == M) {
    for (int num : permutation) {
      cout << num << " ";
    }
    cout << endl;
    return;
  }

  for (int i = 0; i < N; i++) {
    permutation.push_back(nums[i]);
    generatePermutationsWithRepetition(nums, permutation, depth + 1, N, M);
    permutation.pop_back();  // 백트래킹
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

  vector<int> permutation;
  generatePermutationsWithRepetition(nums, permutation, 0, N, M);

  return 0;
}
