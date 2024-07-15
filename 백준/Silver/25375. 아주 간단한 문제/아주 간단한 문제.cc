#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Q; cin >> Q;
	while (Q--) {
		ll a, b; cin >> a >> b;
		if (b % a == 0 && a < b) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}