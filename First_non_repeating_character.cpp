#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {
  vector<int>arr(26,0);
  int ans = -1;
  for(int i = 0;i < str.size();i++){
    arr[str[i] - 'a']++;
  }
  for(int i = 0;i < str.size();i++){
    if(arr[str[i]- 'a'] == 1){
      return str[i] ; 
   }    
  }
  return str[0] ;
}
