/* 백터 기준
#include <iostream>
#include <vector>

#define endl "\n"
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N;
  vector<int> plusVec(10000001, 0);
  vector<int> minusVec(10000001, 0);
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (num >= 0) {
      plusVec[num]++;
    } else {
      minusVec[-num]++;
    }
  }
  cin >> M;
  for (int j = 0; j < M; j++) {
    int num;
    cin >> num;
    if (num >= 0) {
      cout << plusVec[num];
    } else {
      cout << minusVec[-num];
    }
    if (j != (M - 1)) {
      cout << " ";
    }
  }
  return 0;
}
*/
/* sort, vector
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int M;
    cin >> M;

    while (M--) {
        int x;
        cin >> x;

        auto lower = lower_bound(v.begin(), v.end(), x);
        auto upper = upper_bound(v.begin(), v.end(), x);

        cout << (upper - lower) << ' ';
    }

    return 0;
}
*/
/*map
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<int, int> mp;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        cout << mp[x] << ' ';
    }

    return 0;
}
*/