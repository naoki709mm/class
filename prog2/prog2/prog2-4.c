/*** 奥屋 直己                                                                  
 *** 課題2 問題1:内積を計算するプログラム
 *** 提出日 5月17日                                                              
 ***/

#include <stdio.h>

#define N 100

int main(void){

  int i=0;
  int dml=0; //小数点の有無
  int bdp=0; //小数点以下の桁数
  double otb=0.0; //小数点以下用の出力
  double otp=0.0; //出力
  char inp[N]; //入力

  printf("文字列を入力してください:");
  scanf("%s",inp);
  
  while(inp[i] != '\0'){ //ナル文字までループ
    if(inp[i] == '.')
      dml=1;             //小数点以下が入力された場合,dmlに1を代入
    switch(dml){         //小数点以下と以上の判定
    case 0:
      if(inp[i] >= '0' && inp[i] <= '9')
	otp=((int)inp[i]-'0')+otp*10.0;
      break;
    case 1:              //小数点以下のみの計算
      if(inp[i] >= '0' && inp[i] <= '9'){
	otb=((int)inp[i]-'0')+otb*10.0;
	bdp++;
      }
      break;
    }
    i++;
  }
  
  for(i=0 ;i<bdp ;i++) //小数点以下の値otbを桁数分割る
    otb/=10.0;
  otp+=otb;            //小数点以下と整数を足す
  
  if(inp[0] == '-')    //マイナスがあった時、出力を負の値にする
    otp=-otp;

  printf("%lf\n",otp);
  

  return 0;
}
