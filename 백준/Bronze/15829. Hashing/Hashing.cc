#include <cmath>
#include <iostream>

#define endl '\n'

using namespace std;

int N;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int a = s[i] - 'a' + 1;
    sum += (a * pow(31, i));
    // cout << sum << " ";
  }
  cout << sum;
  return 0;
}