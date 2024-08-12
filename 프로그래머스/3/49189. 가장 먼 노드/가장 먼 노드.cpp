#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int cost;
    int to;    
    bool operator<(Node right) const {
        return cost > right.cost;
    }
};
priority_queue<Node> pq;
vector<Node> v[20005];


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0; i<edge.size(); i++){
        int from = edge[i][0];
        int to = edge[i][1];
        int cost = 1;
        v[from].push_back({cost, to});
        v[to].push_back({cost, from});
    }
    int dist[20005];
    
    for(int i = 1; i<=n; i++){
        dist[i] = 1e9;    
    }
    dist[1] = 0;
    pq.push({0, 1});
    int maxResult = 0;
    while(!pq.empty()){
        Node nowNode = pq.top();
        pq.pop();
        int now = nowNode.to;
        int nowCost = nowNode.cost;
        if(dist[now] < nowCost) continue;
        for(int i=0; i<v[now].size(); i++){
            Node nextNode = v[now][i];
            int next = nextNode.to;
            int nextCost = nextNode.cost;
            if(dist[next] <= dist[now] + nextCost) continue;
            dist[next] = dist[now] + nextCost;
            if(dist[next] > maxResult) maxResult = dist[next];
            pq.push({dist[next], next});
        }
    }
    for(int i=1; i<=n; i++){
        if(dist[i] == maxResult){
            answer++;
        }
    }        
    
    return answer;
}