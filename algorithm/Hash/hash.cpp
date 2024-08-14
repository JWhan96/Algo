#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node {
  int row;
  int col;
  bool operator==(Node right)  // 모든 데이터에 대해서  "=="  작성
      const {  // 같은 HashValue에서 정확한 key의 data를 찾기 위해 사용
    return row == right.row && col == right.col;
  }
};

struct HashFunction_return1 {  // function object
  size_t operator()(int key)
      const {  // <- const: 이 함수에서는 함수 바깥의 다른 data를 수정 X
    return 1;
  }
};

struct HashFuncNode {
  size_t operator()(Node key) const {
    // 좌표 범위: 세로:1~10000, 가로:1~10000
    return key.row * 10000 + key.col;  // HashFunction을 어떻게 계산하면
                                       // 좋을까요~~~~? ex) row : 987, col : 123
                                       // => 9870123
  }
};

struct HashFuncVector {
  size_t operator()(vector<int> key) const {
    size_t ret = 0;
    for (auto el : key) ret += el;
    return ret;
  }
};

int main() {
  // containers 4가지
  // 1. sequence containers
  // 2. associative containers
  //    - set : collection of unique keys, sorted by keys
  //    - map : collection of key-value pairs, sorted by keys, keys are unique
  // 3. unordered associatives containers
  //    - unordered_set : collection of unique keys, hashed by keys
  //    - unordered_map : collection of key-value pairs, hashed by keys, keys
  //    are unique
  // 4. container adaptors
  //

  // sorted -> hashed
  unordered_map<int, Node> um;
  // data 추가
  um.insert({1, {5, 3}});  // 1 -> 5,3
  um.insert({5678, {12, 9}});
  um.insert({9, {21, 4}});
  um.insert({7, {8, 9753}});
  um.insert({0, {1910, 32}});
  um.insert({-2134567890, {2134567890, 123456798}});
  // data 수정 or 추가
  // ex) 1번 점의 좌표를 951, 7753으로 바꾸고 싶다.
  um[1] = {951, 7753};  // <- 이미 있는 key라서 해당 key의 value를 수정
  um[123] = {987, 4};  // <- 없는 key로 사용? => 추가된다.

  if (um[-1].row == 0 && um[-1].col == 0) {  // <- key : -1로 data가 추가
    cout << "1" << endl;
  }
  // ==0 으로 비교한 부분은 단순히 비교를 위해 1을 출력하는 부분
  // [] operator를 사용하는 순간 데이터 추가가 된 다음 key = -1인 값에
  // 기본적으로 0, 0이 추가 그 이후 비교를 하기 때문에 1이 출력된다.

  // data 삭제
  um.erase(-1);  // 해당 key의 data 삭제

  // data 찾기
  // - 특정 key의 iterator 가져오기
  auto it_minus = um.find(-2134567890);
  // 응용 : 특정 key가 존재???
  if (it_minus != um.end())  // 찾지 못하면 end
    cout << "find";
  else
    cout << "can't find.";

  cout << "\n";
  // 모든 data 출력
  for (auto it = um.begin(); it != um.end(); it++) {
    // 모든 key, value를 출력
    cout << "key : " << (*it).first << ", value : " << (*it).second.row << ", "
         << (*it).second.col << "\n";

    cout << "key : " << it->first << ", value : " << it->second.row << ", "
         << it->second.col << "\n";
  }

  map<string, int> m2;
  unordered_map<string, int> um2;

  m2.insert({"one", 951});
  m2.insert({"tow", 123});
  m2.insert({"three", 753});
  m2.insert({"four", 32});
  m2.insert({"five", 777});

  um2.insert({"one", 951});
  um2.insert({"tow", 123});
  um2.insert({"three", 753});
  um2.insert({"four", 32});
  um2.insert({"five", 777});

  int de = 1;

  unordered_set<string> us;
  // 추가
  us.insert("one");
  us.insert("SSAFY");
  us.insert("\0");
  us.insert("two");
  us.insert("three");
  us.insert("three");
  us.insert("four");

  // 삭제
  // -> 삭제하고 싶은거 선착순 1명
  us.erase("four");

  // 특정 data의 iterator 찾기
  auto it_word = us.find("one");
  for (int i = 0; i < 10; i++) cout << *it_word << " ";
  cout << endl;

  // 모든 data 출력
  for (auto it = us.begin(); it != us.end(); it++) cout << *it << " ";
  cout << endl;
  for (auto setWord : us) cout << setWord << " ";
  cout << endl;

  unordered_map<int, int> hashValue_origin;
  unordered_map<int, int, HashFunction_return1> hashValue_1;
  // hash function을 제대로 작성해야함
  // 1. 계산에 반복이 최대한 적도록
  // 2. 최대한 충돌이 발생 X
  cout << "origin start" << "\n";
  for (int i = 0; i < 1000000; i++) hashValue_origin[i] = i;
  cout << "origin end" << "\n";

  // 전부 같은 해쉬 값에 저장될때 찾는데 O(N)시간이 걸리고 하나 추가할때마다 더
  // 걸리므로 시간이 엄청 오래걸림
  cout << "return1 start" << "\n";
  for (int i = 0; i < 10000; i++) hashValue_1[i] = i;  // <- O(N)
  cout << "return1 end" << "\n";

  unordered_map<Node, int, HashFuncNode> numNode;  // <- 시간복잡도 : O(1)
  numNode.insert({{5, 3}, 7});
  numNode.insert({{1, 7}, 6});
  numNode.insert({{8, 5}, 4});
  numNode.insert({{3, 5}, -1});

  Node a = {8, 5};
  cout << numNode[a] << "\n";

  unordered_map<vector<int>, int, HashFuncVector> vectorKey;
  vectorKey.insert({vector<int>(10, 1), 5});
  vectorKey.insert({vector<int>(2, 2), 1});
  vectorKey.insert({vector<int>(5, 3), 7});
  vectorKey.insert({vector<int>(1, 999), 2});
}
