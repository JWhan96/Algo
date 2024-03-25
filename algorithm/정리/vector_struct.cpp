#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<pair<int, string>> a;
  a.push_back(make_pair(3, "안녕"));
  string c = "놀러와";
  a.push_back(make_pair(2, c));
  cout << a[0].first << " " << a[0].second;
  cout << a[1].first << " " << a[1].second;

  struct Person {
    string name = "진우";
    int age = 29;
    float height = 175;
  };

  vector<Person> people;

  // Person 객체를 벡터에 추가
  people.push_back(Person());  // 기본 생성자를 사용하여 추가
  people.push_back({"민수", 25, 180});  // 초기화 리스트를 사용하여 추가

  // 벡터의 내용을 반복하여 출력
  for (const Person& person : people) {
    cout << "Name: " << person.name << ", Age: " << person.age
         << ", Height: " << person.height << endl;
  }

  return 0;
}