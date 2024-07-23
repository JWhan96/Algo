#include <iostream>

using namespace std;

int result;
int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    string s;
    s = to_string(i);
    if (s.size() == 1) {
      if (i + i == N) {
        result = i;
        break;
      }
    }
    if (s.size() == 2) {
      int a = i / 10;
      int b = i % 10;
      if (i + a + b == N) {
        result = i;
        break;
      }
    }
    if (s.size() == 3) {
      int a = i / 100;
      int b = i % 100;
      int c = b / 10;
      int d = b % 10;
      if (a + c + d + i == N) {
        result = i;
        break;
      }
    }
    if (s.size() == 4) {
      int a = i / 1000;
      int b = i % 1000;
      int c = b / 100;
      int d = b % 100;
      int e = d / 10;
      int f = d % 10;
      if (a + c + e + f + i == N) {
        result = i;
        break;
      }
    }
    if (s.size() == 5) {
      int a = i / 10000;
      int b = i % 10000;
      int c = b / 1000;
      int d = b % 1000;
      int e = d / 100;
      int f = d % 100;
      int g = f / 10;
      int h = f % 10;
      if (a + c + e + g + h + i == N) {
        result = i;
        break;
      }
    }
    if (s.size() == 6) {
      int a = i / 100000;
      int b = i % 100000;
      int c = b / 10000;
      int d = b % 10000;
      int e = d / 1000;
      int f = d % 1000;
      int g = f / 100;
      int h = f % 100;
      int j = h / 10;
      int k = h % 10;
      if (a + c + e + g + j + k + i == N) {
        result = i;
        break;
      }
    }
    if (s.size() == 7) {
      int a = i / 1000000;
      int b = i % 1000000;
      int c = b / 100000;
      int d = b % 100000;
      int e = d / 10000;
      int f = d % 10000;
      int g = f / 1000;
      int h = f % 1000;
      int j = h / 100;
      int k = h % 100;
      int l = k / 10;
      int m = k % 10;
      if (a + c + e + g + j + l + m + i == N) {
        result = i;
        break;
      }
    }
  }
  cout << result;
}