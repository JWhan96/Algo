#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow; // 전체 타일 수

    for(int height = 3; height <= sqrt(sum); height++) {
        if(sum % height == 0) {
            int width = sum / height; // 가로 길이 계산
            if((width - 2) * (height - 2) == yellow) { // 내부 노란색 타일이 맞는지 확인
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    
    return answer;
}
