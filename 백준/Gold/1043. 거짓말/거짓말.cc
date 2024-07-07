#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int numTruth;
    cin >> numTruth;
    vector<int> truthPeople(numTruth);
    for (int i = 0; i < numTruth; ++i) {
        cin >> truthPeople[i];
    }

    vector<vector<int>> parties(m);
    for (int i = 0; i < m; ++i) {
        int partySize;
        cin >> partySize;
        parties[i].resize(partySize);
        for (int j = 0; j < partySize; ++j) {
            cin >> parties[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < parties[i].size(); ++j) {
            unite(parent, parties[i][0], parties[i][j]);
        }
    }

    unordered_set<int> truthRoots;
    for (int i = 0; i < numTruth; ++i) {
        truthRoots.insert(find(parent, truthPeople[i]));
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        bool canLie = true;
        for (int j = 0; j < parties[i].size(); ++j) {
            if (truthRoots.find(find(parent, parties[i][j])) != truthRoots.end()) {
                canLie = false;
                break;
            }
        }
        if (canLie) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
