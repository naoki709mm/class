/*** 奥屋 直己
 *** 課題 5 問題 1 : 汎整数型の変数の最大値を求めるプログラム
 ***
 ***/

#include <stdio.h>
#include <limits.h>

#define UPDATE_SHRT 1
#define UPDATE_INT 1000
#define UPDATE_LONG 10000

typedef short int shrt;
typedef unsigned short int ushrt;
typedef signed int sint;
typedef unsigned int uint;
typedef long int lng;
typedef unsigned long int ulong;

int main(void){
  
  shrt n_shrt=0;
  ushrt n_ushrt=0,tmp_shrt;
  sint n_int=0;
  uint n_uint=0,tmp_int;
  lng n_long=0;
  ulong n_ulong=0,tmp_long;
  int j=0;
  
  do{
    switch(j){
    case 0:
      n_shrt+=UPDATE_SHRT;
    case 1:
      tmp_shrt=n_ushrt;
      n_ushrt+=UPDATE_SHRT;
    case 2:
      n_int+=UPDATE_INT;
    case 3:
      tmp_int=n_uint;
      n_uint+=UPDATE_INT;
    case 4:
      n_long+=UPDATE_LONG;
    case 5:
      tmp_long=n_ulong;
      n_ulong+=UPDATE_LONG;
      break;
    }
    if(j == 0 && n_shrt < tmp_shrt){
      j=1;
      printf("-------short--------\n");
      printf("算出 : %d\n真値 : %d\n",tmp_shrt,SHRT_MAX);
    }
    if(j == 1 && n_ushrt < tmp_shrt){
      j=2;
      printf("---unsigned short---\n");
      printf("算出 : %d\n真値 : %d\n",tmp_shrt,USHRT_MAX);
    }
    if(j == 2 && n_int < tmp_int){
      j=3;
      printf("--------int---------\n");
      printf("算出 : %u\n真値 : %d\n",tmp_int,INT_MAX);
    }
    if(j == 3 && n_uint < tmp_int){
      j=4;
      printf("----unsigned int----\n");
      printf("算出 : %u\n真値 : %u\n",tmp_int,UINT_MAX);
    }
    if(j== 4 &&n_long < tmp_long){
      j=5;
      printf("--------long--------\n");
      printf("算出 : %ld\n真値 : %ld\n",tmp_long,LONG_MAX);
    }
  }while(n_ulong > tmp_long);
  printf("-----unsigned long------\n");
  printf("算出 : %ld\n真値 : %ld\n",tmp_long,ULONG_MAX);
  
  return 0;
  
}
