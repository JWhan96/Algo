#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int circle(string num) {
  vector<vector<int>> comp1(4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      comp1[i].push_back(num[(i + j) % 4] - '0');
    }
  }
  sort(comp1.begin(), comp1.end());

  int smallV = 0;
  for (int i = 0; i < 4; i++) {
    smallV = smallV * 10 + comp1[0][i];
  }
  // cout << smallV << endl;
  return smallV;
}

int main() {
  vector<int> arr;

  for (int i = 0; i < 4; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  vector<vector<int>> comp(4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      comp[i].push_back(arr[(i + j) % 4]);
    }
  }
  sort(comp.begin(), comp.end());

  int smallestValue = 0;
  for (int i = 0; i < 4; i++) {
    smallestValue = smallestValue * 10 + comp[0][i];
  }

  int cnt = 0;
  for (int i = 1111; i <= smallestValue; i++) {
    string a = to_string(i);
    bool acheck = false;
    for (int idx = 0; idx < a.size(); idx++) {
      if (a[idx] == '0') {
        acheck = true;
        break;
      }
    }
    if (acheck) continue;
    int result = circle(a);
    if (result == i) cnt++;
  }

  cout << cnt;

  return 0;
}
