## 인접행렬
- 노드개수가 대략 1000, 그리고 간선개수가 많을 때 사용
- 장점 : 특정 간선 정보 찾기
- 모든 node간의 관계를 전부 표현
- 단점 : 메모리 낭비

## 인접리스트
- 노드개수가 1000~10만대, 즉 노드개수가 많을 때 사용
- 장점 : 메모리 낭비X, 필요한 만큼만 메모리 소비
- 단점 : 특정 간선에 대한 정보를 찾기 힘들다
- from -> to, from에 대해서만 정리
- 갈 수 없는 것에 대한 정보가 따로 X

## vector
- vector : 메모리를 추가해가면서 저장할 수 있는 구조
- vector<저장할 자료형> 이름
- vector<int> v
- vector.push_back(value) : vector의 맨 뒤에 메모리를 추가하여 value를 저장
- v.push_back(10)
- v.push_back(5)
- v.push_back(1)
- v.push_back(15)
vector.size() : vector가 갖고있는 data개수 
for (int i = 0; i < v.size(); i++)
  cout << v[i] << " ";
vector.pop_back() : vector의 맨 뒤의 data를 삭제
v.pop_back();

## DFS
- 특정 점으로부터 여러개의 간선을 통해 갈 수 있는 점 찾기
- 깊이 우선 탐색