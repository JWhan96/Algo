#include <string>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int rec = rectangle.size();
    queue<pair<int, int>> q;
    int arr[102][102] = {};
    int vis[102][102] = {};
    int dx[] = {0, 1, -1, 0};
    int dy[] = {1, 0, 0, -1};
    
    for(int i = 0; i < rec; i++){
        for(int x = rectangle[i][0] * 2; x<=rectangle[i][2]*2; x++){
            for(int y = rectangle[i][1] * 2; y<=rectangle[i][3]*2; y++)
                arr[x][y] = 1;
        }
    }
    
    for(int i = 0; i < rec; i++){
        for(int x = (rectangle[i][0] * 2)+1; x<rectangle[i][2]*2; x++){
            for(int y = (rectangle[i][1] * 2)+1; y<rectangle[i][3]*2; y++)
                arr[x][y] = 0;
        }
    }
    
    q.push({characterX*2, characterY*2});
    vis[characterX*2][characterY*2] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        if(cur.X == itemX*2 && cur.Y == itemY *2){
            answer = (vis[cur.X][cur.Y]-1) / 2;
            return answer;
        }
        
        for(int d = 0; d < 4; d++){
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            if(nx < 0 || ny < 0 || nx >= 102 || ny >= 102) continue;
            if(vis[nx][ny] > 0 || arr[nx][ny] == 0) continue;
            q.push({nx, ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            
            
        }
        
    }
    
    return answer;
}