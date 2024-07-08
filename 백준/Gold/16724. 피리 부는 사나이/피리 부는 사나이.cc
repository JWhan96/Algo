#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
pair<int, int> parent[MAX][MAX];
char b[MAX][MAX];
bool visited[MAX][MAX];

pair<int, int> Find(pair<int, int> p) {
    if(parent[p.first][p.second] == p) {
        return p;
    }
    return parent[p.first][p.second] = Find(parent[p.first][p.second]);
}

void Union(pair<int, int> a, pair<int, int> b) {
    auto pa = Find(a), pb = Find(b);

    if(pa != pb) {
        parent[pa.first][pa.second] = pb;
    }
}

void dfs(int r, int c) {
    visited[r][c] = true;

    int nr = r, nc = c;
    switch(b[r][c]) {
        case 'U':
            nr--;
            break;
        case 'D':
            nr++;
            break;
        case 'L':
            nc--;
            break;
        default:
            nc++;
    }

    if(Find({r, c}) != Find({nr, nc})) {
        Union({r, c}, {nr, nc});
    }

    if(visited[nr][nc]) {
        return;
    }

    dfs(nr, nc);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
            parent[i][j] = {i, j};
        }
    }

    for(int i = 1; i <= n; i++)  {
        for(int j = 1; j <= m; j++) {
            if(!visited[i][j]) {
                dfs(i, j);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ans += (parent[i][j] == make_pair(i, j));
        }
    }

    cout << ans << '\n';
    return 0;
}