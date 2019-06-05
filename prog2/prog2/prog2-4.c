/*** 奥屋 直己                                                      
 *** 課題2 問題4:入力した数字を数値に変換するプログラム
 *** 提出日 5月27日     
 *** 再提出日 5月29日
<<<<<<< HEAD
=======
 *** 再々提出日 6月5日
>>>>>>> 61bebe578912592396ee03ebe89b43e681e6db6d
 ***/
 
#include <stdio.h>
 
#define N 100
 
int main(void){
<<<<<<< HEAD

  int i=0,j;
  int pnt=0;
  double dcm=1.0;
  double out=0.0; //出力
  double out_u=0.0; //小数点以下用の出力
=======
   
  int i=0;
  int pnt=0; //コンマ
  double dml=1.0;
  double out=0.0; //出力
>>>>>>> 61bebe578912592396ee03ebe89b43e681e6db6d
  char inp[N]; //入力
  
  printf("文字列を入力してください:");
  scanf("%s",inp);
  
  while(inp[i]){              //ナル文字までループ
<<<<<<< HEAD
    if(inp[i] == '.'){        //小数点があった場合，文字列を反対から走査
      pnt=1;
=======
    if(inp[i] == '.')
      pnt=1;
    else if(pnt == 0 && inp[i] >= '0' && inp[i] <= '9') //小数点以上の計算
      out=((int)inp[i]-'0')+out*10; 
    else if(pnt == 1 && inp[i] >= '0' && inp[i] <= '9'){
      dml/=10.0;
      out+=((int)inp[i]-'0')*dml; 
>>>>>>> 61bebe578912592396ee03ebe89b43e681e6db6d
    }
    else if(pnt == 0 && inp[i] >= '0' && inp[i] <= '9') //小数点以上の計算
      out=((int)inp[i]-'0')+out*10; 
    else if(pnt == 1 && inp[i] >= '0' && inp[i] <= '9')
      dcm/=10;
      out+=((int)inp[i]-'0')*dcm;
    i++;
  }
  
  if(inp[0] == '-')    //マイナスがあった時、出力を負の値にする
    out=-out;
  
  printf("%lf\n",out);
  
  return 0;
}
