#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
   
//     while(true){
//         if(abs(a - b) == 1){
//             return answer;
//         }
//         if(a%2 == 0){
//             a = a/2;
//         }else{
//             a = (a+1)/2;
//         }
//         if(b%2 ==0){
//             b =  b/2;
//         }else{
//             b = (b+1)/2;
//         }
        
        
//         answer++;
//     }
    while (a != b) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
    }
    


    return answer;
}