#include <iostream>
#include <vector>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<int>> arr(H, vector<int>(W, 0));
  vector<int> result(10000001, 0);
  int num_result=10000001;
  int num=0;

  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      cin >> arr[i][j];
      result[arr[i][j]]++;
    }
  }
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      if(result[arr[i][j]]==num){
        if(arr[i][j] < num_result){
          num_result=arr[i][j];
          // num = result[arr[i][j]];

        }
      }
      else if(result[arr[i][j]]>num){
        num_result=arr[i][j];
        num = result[arr[i][j]];        
      }
    }
  }

  cout << num_result;


  return 0;
}