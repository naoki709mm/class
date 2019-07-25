/*** 奥屋 直己
 *** 課題 5 問題 1 : 汎整数型の変数の最大値を求めるプログラム
 ***
 ***/

#include <stdio.h>
#include <limits.h>

#define UPDATE 1

typedef short int shrt;
typedef unsigned short int ushrt;
typedef int dint;
typedef unsigned int uint;
typedef long int lng;
typedef unsigned long int ulogn;

int main(void){
  
  uint n,tmp;
  int i;
  
  do{
    tmp=n;
    n+=UPDATE;
    i++;
  }while(tmp < n);

  printf("算出 : %ld\n真値 : %ld\n",tmp,UINT_MAX);
  
  return 0;
  
}
