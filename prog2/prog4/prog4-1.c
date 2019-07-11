/*** 氏名 奥屋 直己
 *** 課題 4 問題 1 : 任意の個数データに対して，その最大値を求めるプログラム
 *** 提出日: ○月○日
 ***/

#include <stdio.h>
#include <stdlib.h>

#define N 100

//配列中の最大値を返す関数
double maxof(int num ,double input[N]){
  
  int i;
  double max;
  
  max=input[0]; //maxの初期値としてinput[0]を代入
  for(i=1 ;i<num ;i++){ //配列inputを走査
    if(input[i] > max) //input[i]がmaxより大きいとmaxをその値に更新
      max=input[i];
  }
  
  return max;
}

int main(int argc ,char *argv[]){
  
  int i;
  int num;
  double input[N];
  
  num=argc-1; //引数の数からコマンドを除外した数を代入
  if(num == 0){ //数値が入力されなかった場合，以下を表示して終了
    printf("./prog4-1 [数値1] [数値2] ・・・\n");
    return 0;
  }
  
  for(i=0 ;i<num ;i++) //引数でchar型で渡された数字をそれぞれdouble型に変換して配列に代入
    input[i]=atof(argv[i+1]); //コマンドを除外するため，要素数に1を足し,走査
  
  printf("Max : %lf\n",maxof(num ,input));
  
  return 0;
}
