#include <iostream>
#include <string>

using namespace std;

int main(){
  string str;
  cin >> str;
  int arr[256] = {0};
  char result;
  for (int i=0; str[i]; i++){
        arr[str[i]]++;
  }

  for (int i=65; i<100; i++){
    if (arr[i]!=0){
      result = i;
      cout << result;      
    }
  }
  return 0;
}