#include <iostream>

using namespace std;

int N;
int point = 1;
string arr[105];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  while (arr[1] != "KBS1") {
    string plus = arr[point + 1];
    string minus = arr[point - 1];
    string now = arr[point];
    if (arr[point] != "KBS1") {
      point++;
      cout << 1;
      continue;
    } else {
      arr[point] = minus;
      arr[point - 1] = now;
      point--;
      cout << 4;
    }
  }
  while (arr[2] != "KBS2") {
    string plus = arr[point + 1];
    string minus = arr[point - 1];
    string now = arr[point];
    if (arr[point] != "KBS2") {
      point++;
      cout << 1;
      continue;
    } else {
      arr[point] = minus;
      arr[point - 1] = now;
      point--;
      cout << 4;
    }
  }
}
