/*** 奥屋 直己                                                      
 *** 課題2 問題4:入力した数字を数値に変換するプログラム
 *** 提出日 5月27日     
 *** 再提出日 5月29日
 *** 再々提出日 6月5日
 ***/
 
#include <stdio.h>
 
#define N 100
 
int main(void){

  int i=0;
  int pnt=0; //小数点以下の有無の判定
  double dml=1.0; //小数点以下の計算に使用．10.0で割っていくため1で初期化
  double out=0.0; //出力
  char inp[N]; //入力
  
  printf("文字列を入力してください:");
  scanf("%s",inp);
  
  while(inp[i]){              //ナル文字までループ
    if(inp[i] == '.')         //小数点があった場合，pntに1を代入
      pnt=1;
    else if(pnt == 0 && inp[i] >= '0' && inp[i] <= '9') //小数点以上の計算
      out=((int)inp[i]-'0')+out*10; 
    else if(pnt == 1 && inp[i] >= '0' && inp[i] <= '9'){ //小数点以下を足し合わせる
      dml/=10.0;                    //dmlを10.0で割って更新し，
      out+=((int)inp[i]-'0')*dml;   //入力された数値に掛けることで小数点以下を計算する
    }
    i++;
  }
  
  if(inp[0] == '-')    //マイナスがあった時、出力を負の値にする
    out=-out;
  
  printf("%lf\n",out);
  
  return 0;
}
