#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, int> v;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    char s = '0';
    for(int i =1; i<=words.size(); i++){
        string now = words[i-1];
        int nowSize =  now.size() - 1;
        
        if(s == now[0] || i==1){
            if(!v[now]){
                v[now] = i;
                s = now[nowSize];
                // cout << s << " ";
            }else{
                if(i%n == 0){
                    answer.push_back(n);
                    answer.push_back(i/n);
                }else{
                    answer.push_back(i%n);
                    answer.push_back(i/n + 1);
                }            
                
                return answer;
            }
        }else{
            if(i%n == 0){
                    answer.push_back(n);
                    answer.push_back(i/n);
                }else{
                    answer.push_back(i%n);
                    answer.push_back(i/n + 1);
                }            
                
                return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);


    return answer;
}