/*** 奥屋 直己
 *** 課題 5 問題 3 :n個のデータの平均と分散を出す
 *** 7月31日
 ***/

#include <stdio.h>
#include <stdlib.h>

//平均値と分散を返す関数
//2つの値を返すため，引数はポインタで受け取る
void average_and_dispersion(int n ,double *dat ,double *ave ,double *dps){
  
  int i;
  double sum=0;
  double tmp;
  
  for(i=0 ;i<n ;i++){ //平均値を計算
    sum+=dat[i];
  }
  ave[0]=sum/n;      //ポインタの先頭の要素に平均値を代入
  
  tmp=ave[0]*ave[0]; //変数tmpに平均の2乗を代入
  sum=0;
  for(i=0 ;i<n ;i++){ //分散を計算
    sum+=dat[i]*dat[i]-tmp;
  }
  dps[0]=sum/n;      //ポインタの先頭の要素に分散を代入
  
}

int main(void){
  
  int n;
  int i;
  double *dat;
  double ave;
  double dps;
  
  printf("データ数n :");scanf("%d",&n);
  if(n <= 0){
    printf("Error\n");
    return 0;
  }
  
  dat=malloc(sizeof(double)*n); //データ数n個のdouble型でメモリを確保
  if(dat == NULL){              //メモリをかくほできなかった場合Errorを返し終了
    printf("Error\n");
    return 0;
  }
  
  for(i=0 ;i<n ;i++){
    printf("データ%d :",i);scanf("%lf",&dat[i]);
  }
  average_and_dispersion(n ,dat ,&ave ,&dps);
  
  printf("-----ans-----\n");
  printf("平均値 :%.3f\n",ave);
  printf("分散   :%.3lf\n",dps);
  
  free(dat); //確保したメモリを解放
  
  return 0;
}
