#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

struct Node {
  int row;
  int col;
};

// flood fill : 영역 <-

//            DFS            vs            BFS
// 공통점        완전 탐색(전부 들린다.)
// 차이점   깊게                        넓게
//            다양한경로                최대한 적은 점을 들려 가는 경로
// FF        그외                        특정 지점(영역)사이의 최대한 적은 점을
// 들려 가는 경로

// 상하좌우로 연결된 점들끼리 같은 '섬'
// 섬이 몇 가지나 존재하는가?

// int MAP[10][10] = {
//     {0,0,1,1,1,1,1,1,1,0},
//     {0,0,1,0,0,0,0,0,1,1},
//     {0,0,1,0,0,0,0,0,1,0},
//     {0,0,1,0,0,0,0,1,1,0},
//     {1,1,1,0,0,0,0,1,0,0},
//     {1,0,0,0,0,1,1,1,0,0},
//     {1,1,1,0,0,1,0,0,0,1},
//     {0,0,1,1,1,1,0,0,1,1},
//     {0,0,0,0,0,0,0,1,1,1},
//     {0,0,0,0,0,0,0,1,1,1},
// };

// int visited[10][10] = { 0, }; // 해당좌표를 들렸는가?

//
// void dfs(int nowRow, int nowCol, int cnt) { // cnt : 몇 번째 섬인가?
//    // now라는 점에 왔다.
//
//    // now->next
//    int dr[] = {-1,1,0,0};
//    int dc[] = {0,0,-1,1};
//    for (int i = 0; i < 4; i++)
//    {
//        int nextRow = nowRow + dr[i];
//        int nextCol = nowCol + dc[i];
//        if (nextRow < 0 || nextCol < 0 ||
//            nextRow >= 10 || nextCol >= 10)
//            continue; // 맵을 벗어났는가?
//        if (MAP[nextRow][nextCol] != 1)
//            continue; // 섬이 아님
//
//        MAP[nextRow][nextCol] = cnt; // 들렸다고 칸을 칠하기!
//        dfs(nextRow, nextCol, cnt);
//    }
//}
//
// void bfs(int stRow, int stCol, int cnt) {
//    //pair<int, pair<int, int>> pa = { 1,{2,3} };
//    //int a = pa.first;
//    //int b = pa.second.first;
//    //int c = pa.second.second;
//
//    //// pair<int, pair<int, int>> <- 2
//    //auto tu = make_tuple(10, 'A', "123");
//    //int first = get<0>(tu);
//    //char ch = get<1>(tu);
//
//    //int a; char chr; string str;
//    //tie(a, chr, str) = tu;
//
//
//
//    // 1. 그래프 구성 // <- now->next로 가는 '관계'
//
//    // 2. queue생성
//    queue< Node > q1; // <- 필수!!!!!!!!
//    queue< pair<int, int> > q2;
//    //<- 왜? queue에 넣었던 정보가 무엇?
//    // 노드 번호 : '노드를 구별할 정보'
//    //    <- 해당 정보만 있으면 정확히 어떤 노드인지 찾을 수 있는 정보
//
//    // 3. 시작점 세팅
//    MAP[stRow][stCol] = cnt;
//    q1.push( { stRow,stCol } );
//    q2.push( { stRow,stCol } );
//
//    while(!q1.empty()){
//        // 4. now꺼내기
//        Node now1 = q1.front(); q1.pop();
//        pair<int, int> now2 = q2.front(); q2.pop();
//
//        // 5. now->next 찾기
//        int dr[] = { -1,1,0,0 };
//        int dc[] = { 0,0,-1,1 };
//        for (int i = 0; i < 4; i++) {
//            int nextRow1 = now1.row + dr[i];
//            int nextCol1 = now1.col + dc[i];
//
//            int nextRow2 = now2.first + dr[i];
//            int nextCol2 = now2.second + dc[i];
//
//            if (nextRow1 < 0 || nextCol1 < 0 ||
//                nextRow1 >= 10 || nextCol1 >= 10)
//                continue;
//
//            if (MAP[nextRow1][nextCol1] != 1)
//                continue; // 섬이 아니면 무시
//
//            // 6. next를 queue에 추가
//            q1.push({ nextRow1, nextCol1 });
//            q2.push({ nextRow2, nextCol2 });
//            MAP[nextRow1][nextCol1] = cnt;
//        }
//    }
//}

// int MAP[10][10] = {
//         {0,0,0,0,0,0,1,0,0,0},
//         {0,0,0,0,0,0,1,0,0,0},
//         {0,0,0,0,0,0,1,0,0,0},
//         {0,0,0,0,1,1,1,0,0,0},
//         {0,0,0,1,1,0,0,0,0,0},
//         {0,0,0,1,0,0,0,0,0,0},
//         {0,0,0,1,0,0,0,0,0,0},
//         {0,0,0,1,0,0,0,0,0,0},
//         {0,0,1,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//     };
//
// int bfs(int stRow, int stCol, int enRow, int enCol) {
//     // 아 그래서 몇 칸가야 하는데?
//     // 내가 몇개의 점을 들려가야 하는가?
//     //      -> visited를 upgrade
//     int visited[10][10] = {0,}; // index : 좌표, value : 해당 점을 들렸는가?
//
//     queue<Node> q;
//     q.push({stRow, stCol});
//     visited[stRow][stCol] = 1;
//     int cnt = 0;
//     while (!q.empty()) {
//         Node now = q.front(); q.pop();
//
//         // 디버깅용코드
//         //cout << cnt << "번째 -----  now : " << now.row << "," << now.col <<
//         "\n";
//         //for (int i = 0; i < 10; i++)
//         //{
//         //    for (int j = 0; j < 10; j++)
//         //        cout << "(" << i << "," << j << ")" << visited[i][j] <<
//         "\t";
//         //    cout << "\n";
//         //}
//         //cout << "\n";
//         //cnt++;
//         //if (now.row == 1 && now.col == 5)
//         //    int de = 1;// 변수하나 만들기(실 사용 X, break point 찍는 용도)
//
//         int dr[] = { -1,1,0,0 };
//         int dc[] = { 0,0,-1,1 };
//         for (int i = 0; i < 4; i++) {
//             int nextRow = now.row + dr[i];
//             int nextCol = now.col + dc[i];
//             if (nextRow < 0 || nextCol < 0 ||
//                 nextRow >= 10 || nextCol >= 10)
//                 continue;
//             if (MAP[nextRow][nextCol] == 1)
//                 continue; // 장애물이 있으면 무시
//             if (visited[nextRow][nextCol] != 0)
//                 continue; // 기록이 존재하면 무시
//
//             q.push({nextRow, nextCol});
//             visited[nextRow][nextCol] = visited[now.row][now.col] + 1;
//         }
//     }
//
//     return visited[enRow][enCol] - 1;
// }

// int MAP[10][10] = {
//         {1,1,1,0,0,0,0,0,0,0},
//         {1,0,1,1,0,0,0,0,0,0},
//         {0,0,0,1,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,2,2,0,0,0},
//         {0,0,0,0,0,2,2,0,0,0},
//     };
//
// int visited[10][10];
// queue<Node> bfs1(int stRow, int stCol) { // <- 해변 찾기(queue에 넣어
// 시작점으로 세팅)
//     queue<Node> q;
//     queue<Node> nextQ; // 바다를 탐색할때 사용할 queue
//     q.push({stRow, stCol});
//
//     while (!q.empty()) {
//         Node now = q.front(); q.pop();
//         int dr[] = {-1,1,0,0};
//         int dc[] = {0,0,-1,1};
//         for (int i = 0; i < 4; i++) {
//             int nextRow = now.row + dr[i];
//             int nextCol = now.col + dc[i];
//
//             if (nextRow < 0 || nextCol < 0 ||
//                 nextRow >= 10 || nextCol >= 10)
//                 continue;
//             if (visited[nextRow][nextCol] != 0)
//                 continue; // 기록이 있는 이미 찾은 좌표면 무시
//
//             if (MAP[nextRow][nextCol] == 1) {// 섬인 경우
//                 visited[nextRow][nextCol] = 1;
//                 q.push({ nextRow , nextCol });
//             }
//             else if (MAP[nextRow][nextCol] == 0) { // 바다인 경우 <- 해변
//                 // 찾고자 하는 점들
//                 visited[nextRow][nextCol] = 1;
//                 nextQ.push({nextRow, nextCol});
//             }
//         }
//     }
//     return nextQ;
// }
//
// int bfs2(queue<Node> q) {
//
//     while (!q.empty()) {
//         Node now = q.front(); q.pop();
//         int dr[] = {-1,1,0,0};
//         int dc[] = {0,0,-1,1};
//         for (int i = 0; i < 4; i++) {
//             int nextRow = now.row + dr[i];
//             int nextCol = now.col + dc[i];
//             if (nextRow < 0 || nextCol < 0 ||
//                 nextRow >= 10 || nextCol >= 10)
//                 continue;
//             if (visited[nextRow][nextCol] != 0)
//                 continue;
//             if (MAP[nextRow][nextCol] == 0) { // 해변인 경우
//                 visited[nextRow][nextCol] = visited[now.row][now.col] + 1;
//                 q.push({ nextRow, nextCol });
//             }
//             else if (MAP[nextRow][nextCol] == 2) { // 찾고자하는 섬
//                 return visited[now.row][now.col];
//             }
//         }
//     }
//     return -1;
// }

// 1점 -> 2점 -> 3점까지 최단 경로
//    BFS    BFS
// -> BFS 1번만으로도 가능
// 2번점에서 BFS를 돌리기!!!!!

// 1점->2점 거리  + 2점->3점 거리
//
// 2->1 거리 + 2->3 거리
//
// 1점      2~9점      10점
//        2~9중 1개만
// BFS(1시작)      BFS(10시작)

// int MAP[10][10] = {
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,1,9,0,0,0,0,0,0,0},
//         {0,0,9,0,0,0,0,0,0,0},
//         {0,9,0,0,0,0,2,0,0,0},
//         {0,9,9,9,9,9,9,9,0,0},
//         {0,0,0,0,0,9,0,0,0,0},
//         {0,0,0,0,0,9,0,0,0,0},
//         {0,0,0,3,0,9,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
// };

int main() {
  // int cnt = 5;
  // for (int i = 0; i < 10; i++) {
  //     for (int j = 0; j < 10; j++) {
  //         if (MAP[i][j] == 1) // 처음 발견되는 섬이다!!!!!
  //         {
  //             //MAP[i][j] = cnt;
  //             bfs(i, j, cnt);
  //             cnt++;
  //         }
  //     }
  // }

  // st -> en까지 몇 번이나 이동해서 가야함???
  /*cout << bfs(0, 0, 7, 7) << "\n";*/

  // queue<Node> q = bfs1(0, 0);
  // cout << bfs2(q);
}