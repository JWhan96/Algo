#include <iostream>

using namespace std;

int main(){
  int type;
  int n, goal;
  cin >> type >> n;
  int arr[10] = {0};
  
  for (int i =0; i<n; i++){
    cin >> goal;
    arr[goal]++;
  }
  if (type==1){
    for (int i=1; i<=9; i++){
      cout << i << ":" << arr[i] << "개" << endl;
    }
  }
  else{
    for (int i=1; i<=9; i++){
      if (arr[i] > 1){
        cout << "중복발견";
        return 0;
      }
    }
    cout << "중복없음";
  }
  return 0;
}