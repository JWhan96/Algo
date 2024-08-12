#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define endl '\n'
#define INF 1e9

using namespace std;

struct Node {
    int cost;
    int to;
    bool operator<(Node right) const { return cost > right.cost; }
};

int cntNode, cntEdge, p;
vector<Node> adj[5005];

vector<int> dijkstra(int start) {
    vector<int> dist(cntNode + 1, INF);
    priority_queue<Node> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int now = pq.top().to;
        int nowCost = pq.top().cost;
        pq.pop();

        if (nowCost > dist[now]) continue;

        for (auto nextNode : adj[now]) {
            int next = nextNode.to;
            int nextCost = nextNode.cost;

            if (dist[next] > dist[now] + nextCost) {
                dist[next] = dist[now] + nextCost;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> cntNode >> cntEdge >> p;
    
    for (int i = 0; i < cntEdge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({cost, to});
        adj[to].push_back({cost, from});
    }

    // 1. 1번 노드에서 모든 노드까지의 최단 경로 계산
    vector<int> distFrom1 = dijkstra(1);

    // 2. p번 노드에서 모든 노드까지의 최단 경로 계산
    vector<int> distFromP = dijkstra(p);

    // 3. 1번 노드에서 p번 노드를 거쳐 마지막 노드로 가는 경로의 비용
    int totalDistViaP = distFrom1[p] + distFromP[cntNode];

    // 4. 1번 노드에서 마지막 노드로 바로 가는 경로의 비용
    int directDist = distFrom1[cntNode];

    // 5. 경로 비교
    if (totalDistViaP == directDist) {
        cout << "SAVE HIM" << endl;
    } else {
        cout << "GOOD BYE" << endl;
    }

    return 0;
}
