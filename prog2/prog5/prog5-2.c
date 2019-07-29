/*** 奥屋 直己
 *** 課題 5 課題2 :
 ***
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 8
#define CON 10 //行列の数値の範囲

void initial(int a[M][N]){
  
  int i,j;
  
  for(i=0 ;i<M ;i++){
    for(j=0 ;j<N ;j++){
      a[i][j]=(int)(drand48()*CON);
    }
  }
}

int main(void){
  
  int a[M][N];
  time_t tp;
  
  time(&tp);
  srand48(tp);
  
  initial(a);
  
  return 0;
}
