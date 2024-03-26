#include <iostream>
#include <queue>

using namespace std;
int n, k;
int cnt;
int dr[] = {-1, +1, 2};
int visit[100001];
int main() {
  cin >> n >> k;
  if (n == k) {
    cout << 0;
    return 0;
  }
  queue<pair<int, int>> q;
  visit[n] = 0;
  q.push(make_pair(n, cnt));
  while (!q.empty()) {
    int now = q.front().first;
    int to_time = q.front().second;
    q.pop();
    for (int i = 0; i < 3; i++) {
      int next;
      int time = to_time + 1;

      // n > k인 경우에만 -1 방향으로 이동 조건을 추가
      if (n > k && dr[i] != -1) {
        continue;  // n > k인 경우는 -1 방향 이외는 무시
      }

      if (dr[i] == 2) {
        next = now * 2;
      } else {
        next = now + dr[i];
      }

      if (next < 0 || next > 100000)
        continue;  // 배열 범위를 벗어나는 경우 무시
      if (visit[next] && visit[next] <= time)
        continue;  // 이미 더 빠른 시간에 방문한 경우 무시

      if (next == k) {
        cout << time;
        return 0;
      }
      q.push(make_pair(next, time));
      visit[next] = time;
    }
  }
  return 0;
}
