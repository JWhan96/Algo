#include <string>
#include <queue>
#include <vector>

using namespace std;

int len;

struct pos{
    string s;
    int dis;
};

bool nextStr(string a, string b){
    int cnt = 0;
    for(int i=0; i<len; i++){
        if(a[i] != b[i]){
            cnt++;
        }
    }   
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    len = begin.size();
    int wordsSize = words.size();
    queue<pos> q;
    int vis[51] = {};
    // begin queue에 넣기
    q.push({begin, 0});
    
    // begin부터 시작해서 한글자 다른(nextStr()) string이 words에 있으면서, 방문한적 없을 때 queue에 넣기
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        if(cur.s == target){
            answer = cur.dis;
            return answer;
        }
        
        for(int i = 0; i<wordsSize; i++){
            if(vis[i] > 0) continue;
            if(nextStr(cur.s, words[i])){
                q.push({words[i], cur.dis+1});
                vis[i] = 1;
            }
        }
    } 
    
    return answer;
}