/*** 氏名(Name): 奥屋 直己
 *** 課題 4 問題 3 : 暗号化プログラム
 *** 提出日: 7月9日
 *** 再提出日: 7月11日
 *** 再々提出日: 7月18日
 ***/
  
#include <stdio.h>
#include <string.h>
  
#define N 100
#define LOW '!'
#define HIGH '~'
  
//暗号文cryptogramを作成する関数
void cryptogram(int n ,char input[N] ,char output[N]){
 
  int i=0;
  int deff;
  int tmp;
  
  deff=HIGH-LOW+1; //!と~の間の差に1を足すことで一周ずらすまでの値を算出
  while(input[i]){       //入力された文字を１文字ずつ走査
    if(input[i] >= LOW && input[i] <= HIGH){ //!と~の間の時のみ以下を実行
      tmp=(int)input[i]+n;                   //tmpにn文字ずらした数値を代入
      while(tmp > HIGH)                      //tmpが~の値より大きい場合
	tmp-=deff;                       //deffを引くことにより!からずらした文字とする
      while(tmp < LOW)                   //同様に!の値より小さい場合も計算する
	tmp+=deff;
      output[i]=(char)tmp;                    //tmpをchar型でinput[i]に代入
    }
    else                                 //!と~の間のとき以外はinputをoutに代入
      output[i]=input[i];
    i++;
  } 
  output[i]='\0';                        //文字列の最後に'\0'を入力
}

int main(void){
  
  int n;
  char input[N];
  char output[N];
  
  printf("文字列を入力 :");
  fgets(input ,N ,stdin);
  if(strlen(input) <= 1){  //入力された文字列が1(\nを含む)以下の場合，Errorを出力
    printf("Error\n");
    return 0;
  }
  
  printf("n = ");
  scanf("%d",&n);
  
  cryptogram(n ,input ,output);
  
  printf("------ans------\n");
  printf("%s",output);
  
  return 0;
}
