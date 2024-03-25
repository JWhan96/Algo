#include <iostream>
#include <vector>

using namespace std;
// 1번패턴 왼 부 오
// 2번 부 왼 오
// 3번 왼 오 부
vector<int> v[1001];
int visited[1001];
int cntLight;

vector<int> first;
vector<int> second;
vector<int> third;

void func(int now) {
  second.push_back(now);
  int next = v[now][0];
  if (next != -1) func(next);
  first.push_back(now);
  // if (next != -1) cout << next << " ";
  next = v[now][1];
  if (next != -1) func(next);
  third.push_back(now);
}
int main() {
  cin >> cntLight;
  int from, left, right;
  for (int i = 0; i < cntLight; i++) {
    cin >> from >> left >> right;
    v[from].push_back(left);
    v[from].push_back(right);
  }
  func(1);
  for (int i = 0; i < first.size(); i++) {
    cout << first[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < second.size(); i++) {
    cout << second[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < third.size(); i++) {
    cout << third[i] << " ";
  }
}
