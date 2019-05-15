/*** 奥屋 直己
 *** 課題1 問題4 :数当てゲーム
 *** 提出日 5月8日
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void ) {
  
  time_t tp;
  int ans; //正解用の変数
  int num; 
  
  time(&tp); srand48(tp); //乱数の初期化
  ans=(int)(drand48()*10000); //10000倍して整数化すると4桁の整数になる
  
  printf("整数を入力してください\n");
  scanf("%d",&num);
  
  while(num != ans){ //整数numと正解の整数ansが同じときループから抜ける
    if(num > ans) //numとansの大小関係の表示
      printf("正解はもっと小さい数です\n");
    else
      printf("正解はもっと大きい数です\n");
    printf("もう一度、整数を入力してください\n");
    scanf("%d",&num);
  }
  printf("正解です\n");
  
  return 0;
}
