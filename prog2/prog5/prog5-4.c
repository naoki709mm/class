/*** 奥屋 直己 
 *** 課題 5 問題 4 : プロフィールを構造体で作成
 *** 7月31日
 ***/ 

#include <stdio.h>

#define N 10
#define M 20

typedef struct profile{
  
  int id;         //ID
  char *name[M];     //名前
  int age;        //年
  double height;  //身長
  double weight;  //体重

}general;

//プロフィールを表示する関数
void print_profile(general *student ,int i){
  
  int j;
  
  for(j=0 ;j<i ;j++){
    printf("------------------\n");
    printf("ID:%2d\n",student[j].id);
    printf("Name:%s\n",student[j].name);
    printf("Age:%3d\n",student[j].age);
    printf("Height:%.1f\n",student[j].height);
    printf("Weight:%.1f\n",student[j].weight);
  }
  
}

//プロフィールに入力する関数
//同時にプロフィールの数も返却
int input_profile(general *student){
  
  int opt;
  int i=0;
  
  do{
    //構造体のメンバにそれぞれ代入
    student[i].id=i+1;
    printf("Name   :");scanf("%s",student[i].name);
    printf("Age    :");scanf("%d",&student[i].age);
    printf("Height :");scanf("%lf",&student[i].height);
    printf("Weight :");scanf("%lf",&student[i].weight);
    printf("------------\n");
    printf("Continue → 1\n");
    printf("Over     → other\n");
    scanf("%d",&opt);
    i++;
  }while(opt == 1 && i < N);
  
  return i; //プロフィール数となるiを返却
  
}  


int main(void){
  
  int i;
  general student[N];
  
  i=input_profile(student);//構造体への入力を行い，プロフィール数をiに代入
  
  print_profile(student ,i);

  return 0;
}
