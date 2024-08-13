#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>  // <- 배열같은 구조
using namespace std;

// int main() {
//   // 4가지 구분
//   // 1. Sequence Container <- 한 줄로 되어있는 구조
//   //    - Array (배열)
//   //    - Vector
//   //    - deque
//   //    - list
//   // 2. Associative Container <- 한 줄 X 일종의 그래프 구조
//   //    - set : collection of unique keys, sorted by keys
//   //    - map : collection of key-value pairs, sorted by keys, keys are
//   unique
//   //
//   // 3. Unordered Associative Container <- 한 줄 X 일종의 Hash구조
//   // 4. Container Adaptor <- 따로 구조를 만든게 X 이미 있던 구조를 upgrade
//   //    - queue
//   //    - priority_queue
//   //    - stack

//   /*
//   set 자료형의 시간복잡도는 Red-Black Tree
//   - 최대한 밸런스있게 data들을 관리
//   - 이진 탐색 트리
//   */
//   set<int> s;
//   s.insert(1234);  // 추가(삽입) <- logN
//   s.insert(111);
//   s.insert(234);
//   s.insert(951);

//   // s.find(111); // 찾기 <- logN
//   // s.erase(111); // 삭제 <- logN
//   // s.clear(); // clear : data를 전부 삭제 <- 1
//   // s.size(); // size : 갖고 있는 data 개수 <- 1

//   // 모든 data를 확인하고 싶은 경우 : iterator를 활용
//   for (auto it = s.begin(); it != s.end(); it++) {
//     cout << *it << "\n";
//   }
//   cout << "\n";

//   set<int>::iterator it_234 = s.find(234);  // <- return : iterator
//   set<int>::iterator it_99999 = s.find(99999);
//   // iterator에서 없다라는 의미 : end();
//   // 그러므로 find iterator로 확인할 때 != s.end()로 확인
//   if (it_234 != s.end()) cout << "234 exist\n";

//   if (it_99999 == s.end()) cout << "99999 not exist\n";

//   // num이라는 수가 존재하는지 여부
//   int num = 951;
//   if (s.find(num) == s.end())
//     cout << "No exist\n";
//   else
//     cout << "Exist\n";

//   s.erase(99999);  // 없는 수를 지워라?
//   // 없는 수를 지우려고 해도 에러는 발생하지 않음

//   // s에서 3번째로 작은 수??????
//   auto it_s = s.begin();
//   cout << *it_s << " ";
//   it_s = next(it_s, 2);
//   cout << *it_s << " ";
//   // next(iterator, cnt) : iterator에서 cnt만큼 다음의 iterator
//   it_s = prev(it_s, 2);
//   cout << *it_s << endl;

//   // 정렬된 구조에서 많이 쓰는 상황
//   /*날짜별로 예약
//   하루에 한명만 예약이 가능*/
//   // 한달동안의 예약 현황
//   set<int> reserveMonth;
//   reserveMonth.insert(1);
//   reserveMonth.insert(5);
//   reserveMonth.insert(15);
//   reserveMonth.insert(12);
//   reserveMonth.insert(8);
//   reserveMonth.insert(20);
//   reserveMonth.insert(18);
//   reserveMonth.insert(17);

//   // A~B(특정 구간 data)라는 날짜 사이의 예약현황
//   // => PRO에서 매우 자주 활용하는 방식
//   cout << "\n A ~ B now reservation\n";
//   int A = 2;
//   int B = 18;
//   // A이상이 '시작하는 위치' (어디부터OK) <- logN
//   auto it_st = reserveMonth.lower_bound(A);
//   // B초과가 '시작하는 위치' (어디부터X)  <- logN
//   auto it_en = reserveMonth.upper_bound(B);
//   for (auto it = it_st; it != it_en; it++) cout << *it << "day\n";

//   //////////////////////////////////////////////////////////////////
//   // map<key, value>
//   map<int, int> m;
//   cout << "Map Structure" << endl;
//   m.insert({4, 10});
//   m.insert({90, 7});
//   m.insert({789, 258});
//   m.insert({2, 77});
//   m.insert({741, 166});
//   m[10] = 951;  // m[10] <- 10을 key로 갖고 있는게 없으면 새로 생성
//                 //      = 951  <- 951을 저장
//   m[90] = 8;  // m[90] <- 90을 key로 갖고 있는게 있으면
//               //       = 8 <- 거기에 8을 저장
//   m.insert({10, 123});
//   // key로 10이 이미 존재 : '무시'
//   // insert는 수정 X, 추가만

//   // data가 어떻게 나올까요??????
//   // key에 대하여 정렬된 순서
//   // map의 find는 set의 find와 동일하게 활용 <- key에 대해서만 확인
//   if (m.find(5) != m.end())
//     cout << "5 exist \n";
//   else
//     cout << "5 not exist\n";

//   m.erase(10);  // <- key를 기반으로 data를 찾아 삭제

//   // 모든 data 찾기
//   for (auto it = m.begin(); it != m.end(); it++) {
//     /* cout << *it << "\n"; // <- 왜 error가 발생???
//     key/value로 묶여있는 iterator이기 때문에(pair로 묶여있음) */
//     pair<int, int> p = *it;
//     int key = p.first;
//     int value = p.second;
//     cout << key << " " << value << "\n";
//   }

//   cout << "Vector Sturcture" << endl;
//   vector<int> v;
//   v.push_back(1);
//   v.push_back(2);
//   v.push_back(3);
//   v.push_back(9);
//   v.push_back(7);
//   v.push_back(8);

//   // -> vector안에 있는 모든 data를 출력
//   for (int i = 0; i < v.size(); i++) cout << v[i];
//   cout << "\n";

//   for (int el : v) {  // python과 비슷한 구문 <- 내부적으로 iterator를 사용함
//     // v에 있는 data들을 하나하나 el에 저장(복사본을 사용)
//     cout << el << " ";
//     el = 10;
//     cout << el << "\n";
//   }

//   // iterator <- pointer와 비슷한 친구
//   // sort(v.begin(), v.end());
//   // v.begin() : ??? <- vector의 시작 위치
//   // v.end()   : ??? <- vector의 끝 위치
//   cout << "iteartor\n";
//   for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//     // pointer에서 그 주소를 찾아가서 data를 가져와라!
//     cout << *it;
//   }
//   cout << endl;
//   // auto : 대입연산자에 맞는 구조로 알아서 설정해라!
//   for (auto it = v.begin(); it != v.end(); it++) {
//     // pointer에서 그 주소를 찾아가서 data를 가져와라!
//     cout << *it;
//   }
// }

// key로 data를 1개만 넣는게 X 2개 이상 (ex. 좌표)
struct Coord {
  int row;
  int col;
  bool operator<(Coord right) const {
    // 주의사항!!!!!!!!
    //  - struct에서 활용하는
    //    모든 data에 대해서 비교 기준을 세워줘야함

    if (row < right.row) return true;  // row가 작은게 우선
    if (row > right.row) return false;

    if (col > right.col) return true;  // col이 큰게 우선
    if (col < right.col) return false;

    return false;
  }
};

int main() {
  set<Coord> s;
  map<Coord, int> m;
  s.insert({1, 5});
  s.insert({5, 4});
  s.insert({1, 3});
  s.insert({5, 3});
  s.insert({1, 7});

  // set은 같은 키는 존재 X
  // 같은지 여부 판단
  // Coord left = { 1,3 };
  // Coord right = { 1,7 };
  // if( !(left < right) && !(right < left) )
  //    => 같다!!!!

  int de = 1;
}
