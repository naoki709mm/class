/*** 奥屋 直己
 *** 課題1 問題4 :数当てゲーム
 *** 提出日 5月8日
 *** 再提出日 5月15日
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void ) {
  
  time_t tp;
  int ans; //正解用の変数
  int num; 
  int sum=0;
  
  time(&tp); srand48(tp); //乱数の初期化
  ans=(int)(drand48()*10000); //10000倍して整数化すると4桁の整数になる
  
  
  do{ //整数numと正解の整数ansが同じときループから抜ける
    printf("整数を入力してください\n");
    scanf("%d",&num);
    if(num > ans) //numとansの大小関係の表示
      printf("正解はもっと小さい数です\n");
    else if(num < ans)
      printf("正解はもっと大きい数です\n");
    sum++; //入力回数の足し合せ
  }while(num != ans);
  
  printf("正解です\n");
  printf("入力回数:%d\n",sum);
  
  return 0;
}
