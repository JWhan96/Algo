#include <string>
#include <vector>
#include <queue>

using namespace std;

// 좌표 관리를 위한 상수 및 구조체
#define X first
#define Y second

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    
    // 1. 거리 및 방문 체크 배열 (-1로 초기화하여 방문 여부 확인)
    vector<vector<int>> dis(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    // 2. 시작점(R) 찾기 및 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                q.push({i, j});
                dis[i][j] = 0; // 시작점은 0회 이동
            }
        }
    }

    // 3. BFS 시작
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        // 현재 지점이 목표 지점(G)이면 즉시 이동 횟수 반환
        if (board[cur.X][cur.Y] == 'G') return dis[cur.X][cur.Y];
        

        for (int d = 0; d < 4; d++) {
            int nx = cur.X;
            int ny = cur.Y;            
            
            // 핵심: 장애물이나 벽을 만날 때까지 해당 방향으로 '쭉' 미끄러지기
            while (true) {
                int tx = nx + dx[d];
                int ty = ny + dy[d];
                
                // 맵 밖으로 나가거나 장애물 'D'를 만나면 그 직전 칸에서 멈춤
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || board[tx][ty] == 'D') break;
                
                nx = tx;
                ny = ty;
            }

            // 미끄러져서 최종적으로 멈춘 지점(nx, ny)이 처음 방문하는 곳이라면
            if (dis[nx][ny] == -1) {
                dis[nx][ny] = dis[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 도달할 수 없는 경우 -1 반환
    return -1;
}