#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {  // 1. 기본적인 정보저장 구조체
  int w;
  int h;
};
struct Node2 {  // 2. queue에서 자신보다 덩치 큰 사람 명수 저장
  int cnt;
  int idx;
  bool operator<(Node2 right) const { return cnt > right.cnt; }
};
int N;
vector<Node> v;            // 처음 정보저장
priority_queue<Node2> pq;  // 등수대로 나열
int arr[55];               // 3. 인덱스 순서대로 등수 저장(출력용)

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int h, w;
    cin >> w >> h;
    v.push_back({w, h});
  }
  for (int i = 0; i < v.size(); i++) {
    Node nowNode = v[i];
    int nowW = nowNode.w;
    int nowH = nowNode.h;
    int more = 0;
    for (int j = 0; j < v.size(); j++) {
      Node nextNode = v[j];
      int nextW = nextNode.w;
      int nextH = nextNode.h;
      if (nowW < nextW && nowH < nextH) {
        more++;
      }
    }
    pq.push({more, i});
  }
  int score = 1;
  int same = 1;
  while (!pq.empty()) {
    Node2 nowNode = pq.top();
    pq.pop();
    int nowIdx = nowNode.idx;
    int nowCnt = nowNode.cnt;
    Node2 nextNode = pq.top();
    int nextIdx = nextNode.idx;
    int nextCnt = nextNode.cnt;
    // if (nowCnt != nextCnt) {
    //   arr[nowIdx] = nowCnt+1;
    // } else {
    //   arr[nowIdx] = score;
    //   same++;
    // }
    arr[nowIdx] = nowCnt + 1;
  }
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}