/*** 奥屋 直己
 *** 課題 5 問題 1 :
 ***
 ***/

#include <stdio.h>
#include <limits.h>

#define UPDATE 1            //nを更新する値

//typedef short int general;            
//typedef unsigned short int general;
//typedef signed int general;
typedef unsigned int general;
//typedef long int general;
//typedef unsigned long int general;

int main(void){
  
  general n=0;
  general tmp;
  int i=0;

  do{
    tmp=n;                  //tmpに変数nを代入
    n+=UPDATE;              //nの値を更新
  }while(tmp < n);          //n-1の値であるtmpと新しい値nを比較

  printf("Ans:%lu\n",tmp);
  
  return 0;

}
