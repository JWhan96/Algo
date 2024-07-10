#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
    int cost;
    int to;
    bool operator<(Edge right) const { return cost > right.cost; }
};

int N, K;
int dist[100001];
priority_queue<Edge> pq;
vector<Edge> v[100001];

void dijkstra(int st, int goal) {
    for (int i = 0; i < 100001; i++) {
        dist[i] = 1e9;
    }
    pq.push({0, st});
    dist[st] = 0;

    while (!pq.empty()) {
        Edge nowEdge = pq.top();
        pq.pop();
        int nowCost = nowEdge.cost;
        int now = nowEdge.to;
        
        if (dist[now] < nowCost) {
            continue;
        }

        for (int i = 0; i < v[now].size(); i++) {
            Edge nextEdge = v[now][i];
            int nextCost = nextEdge.cost;
            int next = nextEdge.to;

            if (dist[next] > dist[now] + nextCost) {
                dist[next] = dist[now] + nextCost;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < 100001; i++) {
        if (i > 0 && i * 2 < 100001) {
            v[i].push_back({0, i * 2});
        }
        if (i + 1 < 100001) {
            v[i].push_back({1, i + 1});
        }
        if (i - 1 >= 0) {
            v[i].push_back({1, i - 1});
        }
    }

    dijkstra(N, K);
    cout << dist[K];
    return 0;
}
