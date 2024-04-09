#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct p {
  int age;
  string name;
};
vector<p> arr;
int n;
bool compare(const p &a, const p &b) {
  return a.age < b.age;  // 나이만을 비교
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    string b;
    cin >> a >> b;
    arr.push_back({a, b});
  }
  stable_sort(arr.begin(), arr.end(), compare);

  for (int i = 0; i < n; i++) {
    cout << arr[i].age << " " << arr[i].name << '\n';
  }

  return 0;
}