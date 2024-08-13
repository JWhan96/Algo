#include <cmath>  // round, floor, ceil 포함
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  double dif;
  int subNum;  // 실제로 빼는 사람의 수
  int result;
  priority_queue<double> pq;
  double cnt;
  double sum;

  cin >> N;
  subNum = round(N * 0.15);  // 0.15퍼 위아래로 빼야함

  for (int i = 0; i < N; i++) {  // 모든 평가 집어넣기
    double num;
    cin >> num;
    pq.push(num);
  }

  for (int i = 0; i < subNum; i++) {  //  최대값 빼기
    pq.pop();
  }

  cnt = N - (subNum * 2);
  for (int i = 0; i < cnt; i++) {
    double realnum;
    realnum = pq.top();
    sum += realnum;
    pq.pop();
  }
  if (cnt == 0) {
    cout << 0;
  } else {
    dif = sum / cnt;
    result = round(dif);
    cout << result;
  }

  return 0;
}
