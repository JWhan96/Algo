#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;

struct Node{
    int row;
    int col;
};
int dr[] = {0, 0, 1, -1};
int dc[] = {-1, 1, 0, 0};
vector<pair<int, unordered_set<int>>> v;
int visit[505][505] = {0, };
int arr[505];

void bfs(int row, int col, const vector<vector<int>>& land){
    int N = land.size();
    int M = land[0].size();
    
    unordered_set<int> s;
    int cnt = 1;
    queue<Node> q;
    q.push({row, col});
    visit[row][col] = cnt;
    s.insert(col);
    while(!q.empty()){
        Node nowNode = q.front();
        q.pop();
        int nowRow = nowNode.row;
        int nowCol = nowNode.col;
        for(int i=0; i<4; i++){
            int nr = nowRow + dr[i];
            int nc = nowCol + dc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(visit[nr][nc] != 0 || land[nr][nc] != 1) continue;            
            q.push({nr, nc});
            cnt++;
            visit[nr][nc] = cnt;
            s.insert(nc);
        }
    }
    
    v.push_back({cnt, s});
    
//     cout << cnt << endl;
    for(int s_child : s){
        arr[s_child] += cnt;
        
    }
//     cout << endl;
    
    return;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int N = land.size();
    int M = land[0].size();
    
    
    for(int i=0; i<N; i++){
        for(int j=0;j<M; j++){
            if(visit[i][j] != 0 || land[i][j] != 1) continue;
            bfs(i, j, land);
        }
    }
    

    for(int i=0; i<M; i++){        
        int result_cnt = arr[i];       

        //result 값 max
        if(result_cnt > answer) answer = result_cnt;
        
    }

    
    return answer;
}