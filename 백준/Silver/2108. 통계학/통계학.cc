#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#define endl '\n'
using namespace std;

struct Node {
  int numResult;
  int realNum;
  bool operator<(Node right) const { return numResult > right.numResult; }
};
struct Node2 {
  int numResult;
  bool operator<(Node2 right) const { return numResult > right.numResult; }
};
int N;
double sum;
int avg;
int sub;
int maxNum = -1e9;
int minNum = 1e9;
Node arr[8005];
int cnt;
priority_queue<Node> pq1;
priority_queue<Node2> pq2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  double realN = N;
  int mid;
  mid = N / 2 + 1;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    sum += num;
    if (maxNum < num) {
      maxNum = num;
    }
    if (minNum > num) {
      minNum = num;
    }
    if (num >= 0) {
      arr[num].numResult += 1;
      arr[num].realNum = num;
    } else {
      arr[-num + 4000].numResult += 1;
      arr[-num + 4000].realNum = num;
    }

    pq1.push({num});
  }

  int roundresult = round(sum / realN);
  cout << roundresult << endl;

  for (cnt = 1; cnt <= mid; cnt++) {
    if (cnt == mid) {
      int numpq = pq1.top().numResult;
      cout << numpq << endl;
    }
    pq1.pop();
  }

  int maxFreq = 0;
  for (int i = 0; i <= 8000; i++) {
    if (arr[i].numResult == maxFreq) {
      pq2.push({arr[i].realNum});
    } else if (arr[i].numResult > maxFreq) {
      maxFreq = arr[i].numResult;
      while (!pq2.empty()) {
        pq2.pop();
      }
      pq2.push({arr[i].realNum});
    }
  }
  if (pq2.size() == 1) {
    cout << pq2.top().numResult << endl;
  } else {
    pq2.pop();
    cout << pq2.top().numResult << endl;
  }

  cout << maxNum - minNum << endl;

  return 0;
}