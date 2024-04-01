#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 조건을 검사하는 함수
bool isValid(const string& s) {
  int balance = 0;
  for (char c : s) {
    if (c == '(')
      balance++;
    else if (c == ')')
      balance--;

    // 언제든지 ')'가 '('보다 많아지면 무효
    if (balance < 0) return false;
  }
  return balance == 0;  // 마지막에 균형이 맞아야 함
}

// DFS를 사용하여 모든 경우의 수 탐색
bool dfs(const string& s, int index, string current) {
  if (index == s.size()) {
    // 모든 선택을 마쳤을 때 유효성 검사
    return isValid(current);
  }

  if (s[index] != '?') {
    // 현재 문자가 '?'가 아니면 그대로 추가
    return dfs(s, index + 1, current + s[index]);
  } else {
    // '?'의 경우 '('와 ')' 모두 시도
    return dfs(s, index + 1, current + '(') || dfs(s, index + 1, current + ')');
  }
}

bool canBeBalanced(const string& s) {
  int open = 0, close = 0, wild = 0;
  for (char c : s) {
    if (c == '(')
      open++;
    else if (c == ')')
      close++;
    else
      wild++;
  }

  // '+'와 '-'의 절댓값 비교로 불가능한 경우 사전 거름
  if (abs(open - close) > wild) return false;
  return dfs(s, 0, "");
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n % 2 != 0) {
    cout << "no\n";  // 1. N이 홀수인 경우 바로 no 출력
  } else {
    cout << (canBeBalanced(s) ? "yes" : "no") << endl;
  }

  return 0;
}
/*
'('는 회사에 사람이 들어가는 것을 의미합니다.
')'는 회사에서 사람이 나가는 것을 의미합니다.
'?'는 '(' 또는 ')' 중 하나를 의미할 수 있습니다.
어떤 시점에서도 회사에 들어간 사람보다 나간 사람이 많을 수 없습니다.
문자열의 끝에 도달했을 때, 들어간 사람의 수와 나간 사람의 수는 같아야 합니다.
1. 우선 N이 홀수인 경우 어느 상황에서도 성립할 수 없으므로 No출력
2. dfs혹은 bfs 이용?
3. 혹은 그냥 단순 숫자 밸런스?

?를 적절히 변환하였을 때 가능한 조합이 있다면 Yes, 어떤상황에서도 불가하다면 No
*/