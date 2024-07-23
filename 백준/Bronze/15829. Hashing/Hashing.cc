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
  unsigned long long sum = 0;
  unsigned long long c = 1;
  for (int i = 0; i < N; i++) {
    int a = s[i] - 'a' + 1;
    if (i != 0) {
      c *= 31;
      c = c % 1234567891;
    }
    unsigned long long b = (a * c);
    sum += b % 1234567891;
    // cout << sum << " ";
  }
  cout << sum % 1234567891;
  return 0;
}