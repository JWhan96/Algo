#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[20][20];
int n,m;

//x좌표, y좌표, count는 현재 구슬이 몇번 상하좌우를 했는지 저장, cost는 구슬이 현재위치에서 다음위치까지의 거리.
struct bead{
    int x;
    int y;
    int count;
    int cost;
};

//구슬 2개
queue<bead> red;
queue<bead> blue;

//벽에 도달한다면 true 리턴
bool reachWall(int x, int y){
    return x<0 or x>= n or y<0 or y>= m;
}

//계속해서 해당 방향으로 직진.
bead straight(bead answer, int dir){
    int x = answer.x;
    int y = answer.y;
    int cost = answer.cost;
    while(true){
        cost++;
        x += dx[dir];
        y += dy[dir];
        if(board[x][y] == 1){
            answer.x = x;
            answer.y = y;
            answer.cost = cost;
            return answer;
        }
        //만일 벽에 도달했다면
        if(board[x][y] == -1 or reachWall(x,y)){
            //벽에 도달한거니까 현재 왔던길을 1번 빼주자.
            answer.x = x - dx[dir];
            answer.y = y - dy[dir];
            answer.cost = cost;
            return answer;
        }
    }
    // return answer;
}

int bfs(){
    
    //10번 이하로 움직이기.
    while(red.front().count < 10 || blue.front().count < 10){
        bead curRed = red.front();
        bead curBlue = blue.front();
        //이때 초기화 하지 않으면 계속 cost가 추가될수 있고 그러면 이전 cost값을 더하면서 cost의 비교에서 문제가 생길수 있다.
        curRed.cost = 0;
        curBlue.cost = 0;
        red.pop();
        blue.pop();

        for(int i = 0;i<4;i++){
            bead nextRed = curRed;
            bead nextBlue = curBlue;

            nextBlue = straight(curBlue,i);
            nextRed = straight(curRed,i);

            //구슬을 움직였으니 다음 구슬에는 1번 움직였다는 것을 메모해주자.
            nextBlue.count = curBlue.count + 1;
            nextRed.count = curRed.count + 1;

            int blueX = nextBlue.x;
            int blueY = nextBlue.y;
            int redX = nextRed.x;
            int redY = nextRed.y;
            //1. blue가 들어간다면.
            if(board[blueX][blueY] == 1){
                continue;
            }
            //2. blue는 이미 뺐으니 red가 들어간다면 정답 처리해주자.
            if(board[redX][redY] == 1){
                return nextRed.count;
            }
            //3. 둘이 겹친다면 거리 파악을 하고 더 멀리 온 구슬을 1번 뒤로 돌리자.
            if(nextBlue.x == nextRed.x && nextBlue.y == nextRed.y){
                if(nextBlue.cost > nextRed.cost){
                    nextBlue.x -= dx[i];
                    nextBlue.y -= dy[i];
                }
                else if(nextRed.cost > nextBlue.cost){
                    nextRed.x -= dx[i];
                    nextRed.y -= dy[i];
                }
            }

            red.push(nextRed);
            blue.push(nextBlue);
        }
    }

    return -1;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char temp;
            cin>>temp;
            if(temp == '#'){
                //벽은 -1
                board[i][j] = -1;
            }
            else if(temp == 'O'){
                //골인지점.
                board[i][j] = 1;
            }
            else if(temp == 'R'){
                bead temp;
                temp.x = i;
                temp.y = j;
                temp.count = 0;
                temp.cost = 0;
                red.push(temp);
            }
            else if(temp == 'B'){
                bead temp;
                temp.x = i;
                temp.y = j;
                temp.count = 0;
                temp.cost = 0;
                blue.push(temp);
            }
        }
    }

    cout<<bfs()<<endl;


    return 0;
}