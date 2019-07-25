/*** 奥屋 直己
 *** 課題 5 問題 1 :
 ***
 ***/

#include <stdio.h>
#include <limits.h>

#define UPDATE 10000000
#define TIME 1000000000000

typedef long int gereral;

int main(void){
  
  gereral n=0;
  gereral tmp;
  int i=0;
  
  do{
    tmp=n;
    n+=UPDATE;
    i++;
    if(i%TIME == 0)
      printf("%ld %ld\n",tmp,n);
    if(n < 0)
      break;
  }while(tmp < n);
  
  printf("%ld %ld\n",tmp,UINT_MAX);
  
  return 0;

}
