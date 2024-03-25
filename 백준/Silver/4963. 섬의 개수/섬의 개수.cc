#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int w, h;
int arr[60][60];
int visit[60][60];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int cnt;
void dfs(int row, int col) {
  for (int i = 0; i < 8; i++) {
    int nr = row + dr[i];
    int nc = col + dc[i];
    if (nr < 0 || nc < 0 || nr >= h || nc >= w) {
      continue;
    }
    if (arr[nr][nc] == 0) {
      continue;
    }
    if (visit[nr][nc] == 1) {
      continue;
    }
    if (arr[nr][nc] == 1) {
      visit[nr][nc] = 1;
      // cout << nr << " " << nc << "다음 nrnc" << endl;
      dfs(nr, nc);
    }
  }
}
int main() {
  while (true) {
    cin >> w >> h;
    // cout << w << "w입력" << h << "h입력" << endl;
    if (w == 0 && h == 0) {
      break;
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> arr[i][j];
      }
    }
    // if (w == 3) {
    //   for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) {
    //       cout << arr[i][j] << " ";
    //     }
    //     cout << "끝" << endl;
    //   }
    // }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (arr[i][j] == 1 && visit[i][j] != 1) {
          // cout << "dfs들어가기전" << i << " " << j << endl;
          visit[i][j] = 1;
          dfs(i, j);
          // cout << "cnt증가" << i << " " << j << "증가했을 때 i j" << endl;
          cnt++;
        }
      }
    }
    cout << cnt << endl;
    cnt = 0;
    memset(arr, 0, sizeof(arr));
    memset(visit, 0, sizeof(visit));
  }

  return 0;
}