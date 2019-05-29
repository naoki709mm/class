/*** 奥屋 直己                                                                  
 *** 課題2 問題4:入力した数字を数値に変換するプログラム
 *** 提出日 5月27日                                                              
 ***/

#include <stdio.h>
#include <string.h>

#define N 100

int main(void){

  int i=0;
  int dml=0; //小数点の有無
  int str;
  int bdp=0; //小数点以下の桁数
  double otb=0.0; //小数点以下用の出力
  double otp=0.0; //出力
  char inp[N]; //入力

  printf("文字列を入力してください:");
  scanf("%s",inp);
  
  str=stren(inp);
  
  while(inp[i]){ //ナル文字までループ
    if(inp[i] == '.')
      dml=1;
    if(dml == 0){
      if(inp[i] >= '0' && inp[i] <= '9')
	otp=((int)inp[i]-'0')+otp*10;
    }
    else{
      if(inp[i] >= '0' && inp[i] <= '9')
	
    }
    i++;
  }
  
  if(inp[0] == '-')    //マイナスがあった時、出力を負の値にする
    otp=-otp;

  printf("%lf\n",otp);
  

  return 0;
}
