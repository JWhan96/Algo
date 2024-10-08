#include <iostream>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

void preorder(int st, const vector<vector<int>> v) {
  int left = v[st][0];
  int right = v[st][1];
  char q = st + 'A';
  cout << q;
  if (left != -1) {
    preorder(left, v);  // 왼쪽 자식이 있을 때만 재귀 호출
  }
  if (right != -1) {
    preorder(right, v);  // 오른쪽 자식이 있을 때만 재귀 호출
  }
}

void inorder(int st, const vector<vector<int>> v) {
  int left = v[st][0];
  int right = v[st][1];
  char q = st + 'A';
  if (left != -1) {
    inorder(left, v);  // 왼쪽 자식이 있을 때만 재귀 호출
  }
  cout << q;
  if (right != -1) {
    inorder(right, v);  // 오른쪽 자식이 있을 때만 재귀 호출
  }
}

void postorder(int st, const vector<vector<int>> v) {
  int left = v[st][0];
  int right = v[st][1];
  char q = st + 'A';
  if (left != -1) {
    postorder(left, v);  // 왼쪽 자식이 있을 때만 재귀 호출
  }
  if (right != -1) {
    postorder(right, v);  // 오른쪽 자식이 있을 때만 재귀 호출
  }
  cout << q;
}

int main() {
  fastio;
  int N;
  cin >> N;
  vector<vector<int>> v(N);
  for (int i = 0; i < N; i++) {
    char root, left, right;
    cin >> root >> left >> right;
    if (left == '.') {
      v[root - 'A'].push_back(-1);
    } else {
      v[root - 'A'].push_back(left - 'A');
    }
    if (right == '.') {
      v[root - 'A'].push_back(-1);
    } else {
      v[root - 'A'].push_back(right - 'A');
    }
  }
  preorder('A' - 'A', v);
  cout << endl;
  inorder('A' - 'A', v);
  cout << endl;
  postorder('A' - 'A', v);
}
