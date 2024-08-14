#include <iostream>
using namespace std;

int MAP[7][3] = {{1, 0, 0},     {1, 2, 0},     {0, 3, 0}, {3, -10, -5},
                 {15, -10, 50}, {15, -10, 10}, {0, 6, 4}};

// dynamic programming : 계산했던 것을 '기록'해서 기록이 있으면 다시 계산 X
int DP[7][3] = {0};  // <- *실제 문제에선 0으로 하면 안될겁니다.*
// DP[row][col] = row, col에서부터 몇 점이 최대인가? <- 계산 결과

// 목표 : DFS에서 '반환받으며' 계산

// 1. 기본적인 DFS구조
int dfs(int row, int col) {
  // 2. 함수 호출하는 것에 의미를 정확하게 부여
  // dfs(row, col) : row, col으로 가라!!!
  // upgrade : row, col에서부터 계산하면 몇이 최선이냐?
  // row, col에서부턴 최대 몇 점까지 가능하냐???

  if (row >= 6) {  // 맨 마지막 층까지 내려가면 멈춰라
    // 3. 맨 끝에서의 결과를 반환
    return MAP[row][col];
  }

  if (DP[row][col] != 0)  // 계산했던 기록이 존재
    return DP[row][col];  // 바로 계산 결과를 가져가라!!!!

  int dr[] = {1, 1, 1};
  int dc[] = {-1, 0, 1};
  int bestChoice = -2134567890;
  for (int i = 0; i < 3; i++) {
    int nr = row + dr[i];
    int nc = col + dc[i];
    if (nr < 0 || nc < 0 || nr >= 7 || nc >= 3) continue;  // 맵을 벗어나면 무시
    if (MAP[nr][nc] == 0) continue;  // 벽을 만나면 무시

    int nextScore = dfs(nr, nc);  // <- next로 가라!!!!!
    // upgrade에서는 nr, nc부터는 최대 몇 점인지 계산해와!!!!

    bestChoice = max(bestChoice, nextScore);  // next들 중 최대 점수 갱신
  }
  // next들 중 최대 점수에 내 점수를 더한게 내 최대 점수
  int nowScore = bestChoice + MAP[row][col];
  DP[row][col] = nowScore;  // <- DP기록
  return nowScore;
}

void bottom_up() {
  int dp[7][3] = {
      0,
  };  // 채워줄 배열
  dp[0][0] = MAP[0][0];
  for (int row = 1; row < 7; row++) {
    for (int col = 0; col < 3; col++) {
      if (MAP[row][col] == 0) continue;  // 내가 벽이면 무시
      // row, col에 대한 '시작점'부터 해당 좌표까지의 최대 점수

      // 바로 위 3좌표를 확인
      int dr[] = {-1, -1, -1};
      int dc[] = {-1, 0, 1};
      int bestChoice = -2134567890;
      for (int i = 0; i < 3; i++) {
        int prevRow = row + dr[i];
        int prevCol = col + dc[i];
        if (prevRow < 0 || prevRow >= 7 || prevCol < 0 || prevCol >= 3)
          continue;
        if (MAP[prevRow][prevCol] == 0) continue;
        bestChoice = max(bestChoice, dp[prevRow][prevCol]);
      }
      dp[row][col] = bestChoice + MAP[row][col];
    }
  }
  int de = 1;  // 이 변수는 사용되지 않으므로 실제로는 필요하지 않음
}

int main() {
  // cout << dfs(0, 0); // 0, 0에서부터 얻을 수 있는 최대 점수
  bottom_up();
}

/*
숙박업소 문제

int dfs(int day, int tic) {
    if (day > n)
        return 0;
    if (d[day][tic] != inf) {
        return d[day][tic];
    }
    int now = inf;
    if (input[day]) {
        now = dfs(day + 1, tic);
    }
    now = min(now, dfs(day + 1, tic) + 10000);
    now = min(now, dfs(day + 3, tic + 1) + 25000);
    now = min(now, dfs(day + 5, tic + 2) + 37000);
    if (tic >= 3)
        now = min(now, dfs(day + 1, tic - 3));
    d[day][tic] = now;
    return now;
}
*/
