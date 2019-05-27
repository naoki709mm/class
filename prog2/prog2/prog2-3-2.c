/*** 奥屋 直己                                                                  
 *** 課題2 問題3:ビンゴプログラム
 *** 提出日 5月22日
 *** 際提出日 5月27日
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define M 100
#define EXC 15
#define BNG 5

int main(void){

  int i,j;
  int tmp;
  int cnt=(int)BNG/2.0; //ビンゴの列数を2で割ることで、ビンゴ配列の真ん中の要素数となる
  int bng[N][N];
  int exc[M]; //除外する要素数を格納する配列
  time_t tp;
  
  time(&tp);
  srand48(tp);
  
  //配列excを0で初期化
  for(i=0 ;i<BNG ;i++){
    for(j=0 ;j<EXC ;j++)
      exc[j]=0;
    for(j=0 ;j<BNG ;j++){
      if(i == cnt && j == cnt){ //真ん中の場合，0を入力
        bng[i][j]=0;
      }
      else{
	do{ //選ばれた要素が1度現れていないかの判断
          tmp=(int)(drand48()*EXC);
        }while(exc[tmp] != 0); //1度使われた要素には1を入力
        exc[tmp]=1;
	bng[i][j]=(tmp+1)+(i*EXC); //選ばれた要素は0~14の範囲なので1を足し、i*EXCをたすことで、その列の範囲の値となる
      }
    }
  }
   
  //ビンゴ風に表示する
  for(i=0 ;i<BNG ;i++){
    for(j=0 ;j<BNG ;j++){
      if(bng[j][i] == 0)
	printf("|free");
      else
	printf("|%3d ",bng[j][i]);
    }
    printf("|\n");
  }
     
  return 0;
} 
