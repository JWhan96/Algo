#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    bool arr[1001] = {0};  // 사람이 제거되었는지 확인하는 배열
    int cnt = 1, idx = 0;
    
    cout << "<";
    while (cnt <= n) {
        int step = 0;
        while (step < m) {
            idx = (idx % n) + 1;  // 원형 구조를 유지하기 위해 idx 증가
            if (!arr[idx]) {      // 아직 제거되지 않았다면
                step++;
            }
        }
        arr[idx] = true;         // 해당 인덱스의 사람을 제거 표시
        if (cnt == n) {
            cout << idx << ">";  // 마지막 숫자 출력
        } else {
            cout << idx << ", "; // 중간 숫자 출력
        }
        cnt++;
    }
    
    return 0;
}
