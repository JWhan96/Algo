#include <iostream>

using namespace std;

int N;
int inT[10];
int outT[10];
int resT;
int resP;
int T, P;

int main() {
  cin >> N;
  for (int i = 0; i < 6; i++) {
    int numT;
    cin >> numT;
    inT[i] = numT;
  }
  cin >> T >> P;
  for (int i = 0; i < 6; i++) {
    if (inT[i] % T != 0) {
      resT += (inT[i] / T) + 1;
    } else {
      resT += (inT[i] / T);
    }
  }
  cout << resT << endl;
  cout << N / P << " " << N % P;
}