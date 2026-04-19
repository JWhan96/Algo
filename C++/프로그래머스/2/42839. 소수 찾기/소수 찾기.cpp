#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int cnt;

bool isPrime(long long n) {
    // 1. 2 미만의 수는 소수가 아님
    if (n < 2) return false;
    
    // 2. 2는 유일한 짝수 소수
    if (n == 2) return true;
    
    // 3. 짝수는 소수가 아님 (2 제외)
    if (n % 2 == 0) return false;

    // 4. 3부터 제곱근까지 홀수들로만 나누어 보기
    // i * i <= n 조건이 sqrt(n)까지 검사하는 것과 같습니다.
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false; // 나누어떨어지면 소수 아님
    }

    return true;
}

void findAllNumbers(string s) {
    set<int> result; // 중복 제거를 위해 set 사용
    
    // next_permutation을 쓰기 전에는 반드시 정렬되어 있어야 함
    sort(s.begin(), s.end());

    do {
        // 현재 순열에서 만들 수 있는 모든 길이의 숫자 추출
        // 예: "17"인 경우 "1", "17" / "71"인 경우 "7", "71"
        for (int i = 1; i <= s.size(); i++) {
            string sub = s.substr(0, i);
            result.insert(stoi(sub)); // 문자열을 숫자로 변환해 저장
        }
    } while (next_permutation(s.begin(), s.end()));

    // 결과 출력
    for (long long n : result) {
       if(isPrime(n)){
           cnt++;
       }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    findAllNumbers(numbers);
    
    return cnt;
}