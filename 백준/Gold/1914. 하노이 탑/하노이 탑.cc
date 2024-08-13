#include <cmath>
#include <iostream>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

void hanoi(int N, int from, int to, int temp) {
  if (N == 1) {
    cout << from << " " << to << endl;
    return;
  }
  hanoi(N - 1, from, temp, to);
  cout << from << " " << to << endl;
  hanoi(N - 1, temp, to, from);
}

int main() {
  fastio;
  int N;
  cin >> N;

  string a = to_string(pow(2, N));

  int x = a.find('.');  // pow 함수 결과가 실수형이기에 소수점 찾기
  a = a.substr(0, x);  // 소수점 앞자리만 나오게하기
  a[a.length() - 1] -= 1;  // string a에 대한 마지막 위치의 인덱스 값에 -1

  cout << a << endl;

  if (N <= 20) {
    hanoi(N, 1, 3, 2);
  }

  return 0;
}
