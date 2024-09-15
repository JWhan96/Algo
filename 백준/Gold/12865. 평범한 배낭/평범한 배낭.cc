#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[103][100003];
int w[103];
int v[103];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - w[i] >= 0)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[n][k] << '\n';

    return 0;
}