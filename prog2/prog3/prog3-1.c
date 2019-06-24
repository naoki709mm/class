#include <stdio.h>
#include <math.h>

double discriminant(double a ,double b ,double c){ //判別式D=b^2-4acを求める関数

  double d;

  d=b*b-4*a*c;

  return d;
}

int main(void){ //メイン関数
  
  double a,b,c;
  double d;
  double tmp1,tmp2;

  printf("ax^2+bx+c=0\n"); //入力
  printf("a=");
  scanf("%lf",&a);
  printf("b=");
  scanf("%lf",&b);
  printf("c=");
  scanf("%lf",&c);

  if(a == 0 && b == 0){ //aとbの両方が0の時、エラーを表示して終了
    printf("エラー\n");
    return 0;
  }
  
  printf("-------ans-------\n");
  
  if(a == 0) //a=0かa≠0を判別
    printf("x=%lf\n",-c/b);
  else{
    d=discriminant(a ,b, c); //判別式の結果を変数dに代入
    if(d < 0)                //d＜0のとき、解なし
      printf("解なし\n");
    else{
      tmp1=-b/(2*a);          //d>0とd=0の時の両方に出てくる式の結果を変数tmp1に代入
      if(d == 0)
	printf("x=%lf\n",tmp1);
      else{
	tmp2=sqrt(d)/(2*a);   //解の公式からtmp1を引いた部分を計算
	printf("x=%lf,%lf\n",tmp1+tmp2,tmp1-tmp2);
      }
    }
  }
  
  return 0;
}
      
