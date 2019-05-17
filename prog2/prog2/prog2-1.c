/*** 奥屋 直己                                                                  
 *** 課題2 問題1:内積を計算するプログラム
 *** 提出日 5月17日                                                              
 ***/

#define N 100

#include <stdio.h>

int main(void){

  int i;
  int n;
  double x[N],y[N]; //ベクトルxとベクトルyをそれぞれ代入する変数
  double inn=0.0; //内積の値を代入する変数

  printf("次数nを入力:");
  scanf("%d",&n);

  if(n <= 0){ //次数nが0以下のとき,Errorを出力して終了
    printf("Error\n");
    return 0;
  }
  
  printf("\nベクトルxを入力\n"); //次数nの回数分ループ
  for(i=0 ;i<n ;i++){ //xを入力
    printf("x%d=",i+1); //次数と合わせるためにi+1とする
    scanf("%lf",&x[i]);
  }

  printf("\nベクトルyを入力\n");
  for(i=0 ;i<n ;i++){ //yを入力
    printf("y%d=",i+1);
    scanf("%lf",&y[i]);
  }
  
  for(i=0 ;i<n ;i++)
    inn+=x[i]*y[i];

  printf("\n内積:%lf\n",inn);

  return 0;
}
