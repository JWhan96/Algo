/*
N*N의 지역이 있다
기계는 1행1열에서 출발
n행n열로 가는게 목표
기계는 오른쪽이나 아래로만 이동가능

지나가는 길에 광물(양수만 존재)이 있으면 그 가치만큼 이득
지나가는 길에 장애물(음수만)이 있다면 그 가치만큼 손해

하지만 딱 한번 T초전으로 되돌아 갈수있는 시간역행장치 존재
(시간역행을 했을 당시의 땅도 가치에 포함)
역행장치 쓰기 전 가치와 손해는 유지

목적지에 도착하였때 가장 높은 가치는?

4 1
1 1 5 5
1 3 4 2
5 3 1 1
1 1 1 1 이런느낌으로 입력
*/