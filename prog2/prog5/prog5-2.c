/*** 奥屋 直己
 *** 課題 5 課題2 :行列の基本操作
 *** 提出日 7月31日
 ***/

#include <stdio.h>

#define N 5 //行
#define M 6 //列

//行列を表示する関数
void print(int array[M][N]){
  
  int i,j;
  
  for(i=0 ;i<M ;i++){
    for(j=0 ;j<N ;j++){
      printf("|%4d",array[i][j]);
    }
    printf("|\n");
  }
  
}

//使い方を表示する関数
void print_how(){
  
  printf("------------How to------------\n");
  printf("対応する数字を入力\n");
  printf("(1)i行目とj行目を入れ替える\n");
  printf("(2)i行目をa≠0倍する\n");
  printf("(3)i行目に,j行目のa≠0倍を加える\n");
  printf("(4)i列目とj列目を入れ替える\n");
  printf("(5)i列目をa≠0倍する\n");
  printf("(6)i列目に,j列目のa≠0倍を加える\n");
  printf("------------------------------\n");
  
}

//初期値にとして0から順番に配列に代入
void initial(int array[M][N]){
  
  int i,j;
  int sum=0;
  
  for(i=0 ;i<M ;i++){
    for(j=0 ;j<N ;j++){
      array[i][j]=sum;
      sum++;
    }
  }
  
}

void swap_row(int array[M][N] ,int row_1 ,int row_2){
  
  int tmp;
  int i;
  
  for(i=0 ;i<N ;i++){
    tmp=array[row_1][i];
    array[row_1][i]=array[row_2][i];
    array[row_2][i]=tmp;
  }
  
}

void multiply_row(int array[M][N] ,int row ,int a){
  
  int i;
  
  for(i=0 ;i<N ;i++)
    array[row][i]*=a;
  
}

void add_row(int array[M][N] ,int row_1 ,int row_2 ,int a){
  
  int i;
  
  for(i=0 ;i<N ;i++)
    array[row_1][i]+=a*array[row_2][i];
  
}

void swap_col(int array[M][N] ,int col_1 ,int col_2){
  
  int i;
  int tmp;
  
  for(i=0 ;i<M ;i++){
    tmp=array[i][col_1];
    array[i][col_1]=array[i][col_2];
    array[i][col_2]=tmp;
  }
  
}

void multiply_col(int array[M][N] ,int col ,int a){
  
  int i;
  
  for(i=0 ;i<M ;i++)
    array[i][col]*=a;
  
}

void add_col(int array[M][N] ,int col_1 ,int col_2 ,int a){
  
  int i;
  
  for(i=0 ;i<M ;i++)
    array[i][col_1]+=a*array[i][col_2];
  
}

//iとjを入力して，Error判定を行う関数
int input(int max){
  
  int tmp;
  
  do{
    scanf("%d",&tmp);
    if(tmp >= max || tmp < 0 )
      printf("Error\nもう一度入力してください:");
  }while(tmp>= max || tmp < 0);
  
  return tmp;
  
}

//倍率aを入力して，Error判定を行う関数
int input_a(){

  int a;
  
  do{
    scanf("%d",&a);
    if(a == 0)
      printf("Error\nもう一度入力してください:");
  }while(a == 0);
  
  return a;
  
}

int main(void){
  
  int array[M][N]; //M×N行列を入れる関数
  int i,j;     //行列の入れ替えの要素指定を代入するための変数
  int a;       //倍率を入れるための変数
  int opt;     //基本操作を指定するための数値を入れる変数
  
  initial(array);
  printf("-----------default-----------\n");
  print(array);
  
  print_how();
  scanf("%d",&opt);
  
  //switch文でオプションを分岐
  switch(opt){
  case 1:
    printf("行数iを入力 :");
    i=input(M);
    printf("行数jを入力 :");
    j=input(M);
    swap_row(array ,i ,j);
    break;
  case 2:
    printf("行数iを入力 :");
    i=input(M);
    printf("倍率aを入力 :");
    a=input_a();
    multiply_row(array ,i ,a);
    break;
  case 3:
    printf("行数iを入力 :");
    i=input(M);
    printf("行数jを入力 :");
    j=input(M);
    printf("倍率aを入力 :");
    a=input_a();
    add_row(array ,i ,j ,a);
    break;
  case 4:
    printf("列数iを入力 :");
    i=input(N);
    printf("列数jを入力 :");
    j=input(N);
    swap_col(array ,i ,j);
    break;
  case 5:
    printf("列数iを入力 :");
    i=input(N);
    printf("倍率aを入力 :");
    a=input_a();
    multiply_col(array ,i ,a);
    break;
  case 6:
    printf("列数iを入力 :");
    i=input(N);
    printf("列数jを入力 :");
    j=input(N);
    printf("倍率aを入力 :");
    a=input_a();
    add_col(array ,i ,j ,a);
    break;
  default:
    printf("Error\n"); //1-6以外の数値を入力するとErrorを表示して終了
    return 0;
  }
  
  printf("-------------Ans-------------\n");
  print(array);
  
  return 0;
}
