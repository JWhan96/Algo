#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(long long i=0; i<=d; i+=k){
        long long a = sqrt(pow(d,2) - pow(i,2));
        answer += (a / k) +1;
        
    }

    
    return answer;
}