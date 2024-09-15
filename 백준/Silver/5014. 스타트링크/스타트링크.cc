#include <algorithm>
#include <iostream>
#include <queue>
#define endl '\n'
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;
typedef long long ll;
struct Node{
  int floor;
  int cnt;
};
int F, S, G, U, D;
bool visit[1000001];

int main() {
  fastio;
  cin >> F >> S >> G >> U >> D;
  queue<Node> q;
  q.push({S, 0});
  visit[S] = 1;
  int result = 0;
  while(!q.empty()){
    Node now = q.front();
    q.pop();
    int nowF = now.floor;
    int nowC = now.cnt;
    if(nowF == G){
      result = nowC;
      break;
    } 
    if(nowF + U <= F && visit[nowF+U] ==0){
      q.push({nowF + U, nowC +1});
      visit[nowF + U] = 1;
    }
    if(nowF - D >= 1 && visit[nowF -D] == 0){
      q.push({nowF -D, nowC +1});
      visit[nowF -D] = 1;
    }

  }

  if(visit[G] == 1){
    cout << result << endl;
  }else{
    cout << "use the stairs" << endl;
  }

 
}