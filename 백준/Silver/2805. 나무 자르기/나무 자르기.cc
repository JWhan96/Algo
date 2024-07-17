#include <iostream>
#include <vector>

using namespace std;

long long N, result;
vector<long long> v;
long long maxTree;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> result;
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        v.push_back(a);
        if (a > maxTree) {
            maxTree = a;
        }
    }

    long long startP = 0;
    long long endP = maxTree;
    long long point = 0;

    while (startP <= endP) {
        point = (startP + endP) / 2;
        long long num = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] > point) {
                num += (v[i] - point);
            }
        }

        if (num < result) {
            endP = point - 1;
        } else {
            startP = point + 1;
        }
    }

    cout << endP << endl;
    return 0;
}
