/*** 奥屋 直己
 *** 課題3 問題4 : 標準正規分布をヒストグラムで表示するプログラム
 *** 提出日 6月25日
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM 100000 //乱数を計算する回数
#define DIV 1000   //*がいくつ分のデータとするかの数
#define PER 0.5   //ヒストグラムの間隔(double型)
#define N 100      //配列の要素数
#define MAX 3.0    //表示したいデータの最大値
#define MIN -3.0   //表示したいデータの最小値

double std_normal_dist(){ //標準正規分布に従う乱数を返却する関数
  
  double x,y;
  double z;
  
  
  x=drand48();
  y=drand48();
  z=sqrt(-2.0*log(x))*cos(2.0*M_PI*y); //標準確率変数に従う乱数を算出
  
  return z;
}

void display(int hst[N]){ //頻度を代入した配列を引数としてヒストグラムを表示する関数
  
  int i,j;
  double tmp=MIN;
  
  for(i=0 ;i<(int)(MAX-MIN)/PER ;i++){ //最大値と最小値の間を分割する回数文ループ
    printf("%5.2f ",tmp);
    tmp+=PER;
    printf("~%5.2f |",tmp);
    for(j=0 ;j<hst[i]/DIV ;j++){      //1つの*をDIV分の個数とした時の頻度分ループ
      printf("*");
    }
    printf("\n");
  }
  
  printf("------------\n");
  printf("*=%d\n",DIV);
}
  

int main(void){

  int hst[N]={}; //ヒストグラムの頻度を代入する配列
  int i;
  double x,y,z;
  time_t tp;
  
  time(&tp);
  srand48(tp);
  
  for(i=0 ;i<NUM ;i++){
    z=std_normal_dist();
    if(z <= MAX && z >= MIN){ //-3~3意外の値の時無視する．
      z=(z+MAX)/PER;  //配列の要素数にあわせるため，最大値MAXを足す．またこれを配列の間隔PERで割り，間隔と要素数を合わす
      hst[(int)z]++; //頻度を入力
    }
  }
  display(hst);
  
  return 0;
}
  
  
