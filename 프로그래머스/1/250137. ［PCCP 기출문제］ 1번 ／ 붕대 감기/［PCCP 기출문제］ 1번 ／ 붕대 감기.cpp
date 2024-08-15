#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int bandage_time = bandage[0];
    int bandage_heal = bandage[1];
    int plus_heal = bandage[2];
    int max_health = health;
    int attack_idx=0;
    int time = 0; // 실제 시간
    for(int i=0; i<attacks.size(); i++){
        int at_time =  attacks[i][0]; // 공격하는 시간
        int at_point = attacks[i][1]; // 공격할 때 깎이는 체력
        if(health == max_health){ 
            time = at_time;
            health -= at_point;
            if(health <= 0){
                answer = -1;
                return answer;
            }
        }else{
            int div_time = at_time - time - 1; // 다음 공격시까지 남은 시간
            int heal_time = 0; // 실제 회복 시간
            while(heal_time != div_time){
                heal_time++;
                health += bandage_heal;
                if(heal_time % bandage_time == 0){
                    health += plus_heal;  // 연속으로 회복했을 때 추가회복
                }               
                
            }
            if(health > max_health){  // 회복시간 다 끝나고 체력이 max를 넘을 수 없으므로 고정
                health = max_health; 
            }
            time = at_time;
            health -= at_point;
            if(health <= 0){
                answer = -1;
                return answer;
            }        
        }
    }
    answer = health;

    
    return answer;
}