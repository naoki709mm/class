/*** 奥屋 直己
 *** 課題1 問題1 \:単価と個数から金額を求め、さらに合計金額と消費税込の金額を計算するプログラム
 *** 提出日
 ***/

#include<stdio.h>

int main(void){
  
  int sum,ttl,tax; //sumを小計金額、ttlを合計金額、taxを消費税とする
  int num,prc; //qtyを個数、prcを単価とする
  
  FILE *fr,*fw;

  if((fr=fopen("input.data","r")) == NULL){ //input.dataが読み込めなかった場合以下を実行
    printf("ファイルを開けません");
  }
  else{
    if((fw=fopen("total.data","w")) == NULL){ //total.dataが読み込めなかった場合以下を実行
      printf("ファイルを開けません");
    }
    else{
      while(!feof(fr)){ //読み取った値が終端でない場合以下を実行
	fscanf(fr,"%d%d\n",&prc,&num);
	sum=prc*num;
	ttl+=sum; //小計金額sumを合計金額ttlに足し合わせる
	fprintf(fw,"%4d  %4d  %5d\n",prc,num,sum);
      }
      fclose(fw); //total.dataを閉じる
    }
    fclose(fr); //input.dataを閉じる
  }

  tax=ttl*0.08;
  printf("  total  :%5d\n",ttl);
  printf("total+tax:%5d\n",ttl+tax);

  return 0;
}
