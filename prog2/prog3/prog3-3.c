/*** 奥屋 直己
 *** 課題3 問題3 : 相性占い
 *** 提出日 6月24日
 ***/

#include <stdio.h>
#include <stdlib.h>

#define N 2
#define A 11
#define B 2
#define C 1
#define D 5

//相性度を求める関数
int compatibility(int y[N] ,int m[N] ,int d[N]){
  
  int w;
  
  w=(A*abs(y[1]-y[0])+B*abs(m[1]-m[0])+C*abs(d[1]-d[0]))%D;
  
  return w;
}

//相性度wを引数としてメッセージを表示する関数
void display(int w){
  
  switch(w){
  case 0:
    printf("相性W=%d 「あまり相性はよくないようです。」\n",w);
    break;
  case 1:
    printf("相性W=%d 「いい仕事仲間になれるでしょう」\n",w);
    break;
  case 2:
    printf("相性W=%d 「よい友だちになれるでしょう」\n",w);
    break;
  case 3:
    printf("相性W=%d 「お互い譲り合えば上手くいくでしょう」\n",w);
    break;
  case 4:
    printf("相性W=%d 「最高のパートナーになれるでしょう」\n",w);
    break;
  }
}

int main(void){
  
  int y[N]; //年
  int m[N]; //月
  int d[N]; //日を代入する配列
  int w;    //相性度を代入する変数
  
  printf("1人目の生年月日を入力:");
  scanf("%d %d %d",&y[0],&m[0],&d[0]);
  printf("2人目の生年月日を入力:");
  scanf("%d %d %d",&y[1],&m[1],&d[1]);
  
  w=compatibility(y ,m ,d);
  
  display(w);
  
  return 0;
}
  
  
  
