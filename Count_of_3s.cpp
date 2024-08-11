#include <bits/stdc++.h> 
long long int countOf3(int x) {
     int count = 0;
     for(int i = 0; i<=x; ++i){
          int num = i;
          while(num>0){
               if(num %10==3){
                    count++;
               }
               num /= 10;
          }
     }
     return count;
}
