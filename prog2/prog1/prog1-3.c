/*** 奥屋 直己
 *** 課題1 問題3 :整数nの平方根を探すプログラム
 *** 提出日 5月8日
 ***/

#include <stdio.h>
#include <math.h>

int main(void){
  
  int i;
  int n;
  int sqt;
  
  printf("整数nを入力してください:");
  scanf("%d",&n);
  
  if(n < 0){ //0以下が入力された場合、Errorを出力し、1を返して終了
    printf("Error\n");
    return 1;
  }
  
  sqt=(int)sqrt(n); //整数nの平方根をint型でsqtに代入
  
  for(i=0 ;i<=sqt ;i++){ //0からsqtまでの値で2すると整数nと同じ値になるものを探し、見つけた場合、結果を表示し、ループから抜ける
    if(n == i*i){
      printf("%dは%dの平方数です\n",n,i);
      break;
    }
    if(i == sqt)  //最後まで走査し見つからなかった場合、以下を表示
      printf("%dは平方数ではありません\n",n);
  }
  
  return 0;
}
