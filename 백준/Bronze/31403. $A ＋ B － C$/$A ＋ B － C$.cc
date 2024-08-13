#include <cmath>
#include <iostream>
#include <vector>

#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

int main() {
  fastio;
  string a, b, c;
  cin >> a >> b >> c;
  int aa, bb, cc;
  aa = stoi(a);
  bb = stoi(b);
  cc = stoi(c);
  cout << aa + bb - cc << endl;
  cout << stoi(a + b) - stoi(c) << endl;
}
