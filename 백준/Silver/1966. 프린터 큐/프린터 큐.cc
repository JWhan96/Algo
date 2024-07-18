#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'

using namespace std;

struct Node {
  int printNum;
  bool check;
  bool operator<(const Node right) const { return printNum < right.printNum; }
};
int T;
int N, M;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int tc = 1; tc <= T; tc++) {  // 테스트 케이스
    cin >> N >> M;
    priority_queue<Node> pq;
    deque<Node> dq;
    int cnt = 0;
    while (!pq.empty()) {
      pq.pop();
    }
    while (!dq.empty()) {
      dq.pop_back();
    }
    for (int n = 0; n < N; n++) {  // 자료 입력
      int printIn;  // 프린터에 들어가는 자료의 중요도
      cin >> printIn;
      if (n == M) {
        dq.push_back({printIn, 1});
        pq.push({printIn, 1});
      } else {
        dq.push_back({printIn, 0});
        pq.push({printIn, 0});
      }
    }
    Node checkNow = pq.top();  // 우선순위큐에서 뽑아내는 구조체
    int maxP = checkNow.printNum;  // 높은 중요도
    bool checkP = checkNow.check;  // 내가 원하는 게 맞는지
    while (!pq.empty() || !dq.empty()) {
      Node realP = dq.front();
      dq.pop_front();
      int realNum = realP.printNum;
      bool realCheck = realP.check;
      if (realNum != maxP) {  // 우선 순위 높은게 아닐때
        dq.push_back(realP);
        continue;
      } else {  // 우선 순위 높은 것일 때
        if (realCheck == 0) {
          pq.pop();
          cnt++;
          checkNow = pq.top();
          maxP = checkNow.printNum;
          checkP = checkNow.check;
        } else {
          cnt++;
          cout << cnt << endl;
          break;
        }
      }
    }
  }

  return 0;
}