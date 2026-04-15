#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
struct Node {
    int row;
    int col;
};
char arr[105][105];
int visit[105][105];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<Node> q;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int N = maps.size();
    int M = maps[0].size();
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            arr[i][j] = maps[i][j];
        }
    }
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            int cnt = 0;
            if(arr[i][j] == 'X' || visit[i][j]==1){
                continue;
            }
            q.push({i, j});
            visit[i][j] = 1;
            int a = arr[i][j] - '0';
            // cout << a << endl;
            cnt += a;
            // 여기 숫자로 변환해야하네
            while(!q.empty()){
                Node now = q.front();
                q.pop();
                int nowRow = now.row;
                int nowCol = now.col;
                for(int i=0; i<4; i++){
                    int nr = nowRow + dr[i];
                    int nc = nowCol + dc[i];
                    if(nr < 0 || nc < 0 || nr>=N || nc >=M) continue;
                    if(arr[nr][nc] == 'X') continue;
                    if(visit[nr][nc] != 0) continue;
                    a = arr[nr][nc] - '0';
                    // cout << a << endl;
                    cnt += a;
                    // 여기도 숫자로 변환
                    q.push({nr, nc});
                    visit[nr][nc] = 1;
                }
            }
            answer.push_back(cnt);
            
        }
    }
    if(answer.size() == 0){
        answer.push_back(-1);
    }else{
        sort(answer.begin(), answer.end());
    }
    
    
    
    
    return answer;
}