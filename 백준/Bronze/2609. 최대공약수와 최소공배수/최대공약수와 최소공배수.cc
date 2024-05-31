#include <iostream>

using namespace std;

int a, b;
;
int max_ab;
int min_ab;
int max_num;
int min_num;

void mn(int ma, int mb) {
  if (ma % mb == 0) {
    max_num = mb;
    return;
  }
  mn(mb, ma % mb);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  max_ab = max(a, b);
  min_ab = min(a, b);
  mn(max_ab, min_ab);
  cout << max_num << '\n';
  min_num = max_ab * min_ab / max_num;
  cout << min_num;
  return 0;
}