#include <iostream>

// gcd 함수 정의
int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int x, y;
  std::cout << "Enter two integers: ";
  std::cin >> x >> y;

  int result = gcd(x, y);
  std::cout << "GCD(" << x << ", " << y << ") = " << result << std::endl;

  return 0;
}
