#include <iostream>
#include <vector>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> prefix_sum(N + 1, vector<int>(N + 1, 0));
    
    // 배열 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            prefix_sum[i][j] = arr[i][j] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }
    
    // 질의 처리
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = prefix_sum[x2][y2] - prefix_sum[x1-1][y2] - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1];
        cout << result << '\n';
    }
    
    return 0;
}