#include<stdio.h>
#include <stdlib.h>
#include <string.h> 

#define N 100

void usage(char *f){ //入力の確認
  int i;

  for(i=0 ;i<N ;i++){
    if(f[i] == 0)
      break;
    switch(f[i]){
      case 'x':
      case 'y':
      case 'z':
      case '+':
        break;
      case '*':
        switch(f[i-1]){
          case 'x':
	  case 'y':
	  case 'z':
	    break;
	  default:
	    printf("error\n");
	    exit(1);
	}
	break;
      default:
	printf("error\n");
	exit(1);
    }
  }
}

char and(char a ,char b){
  if(a == '1' && b == '1')
    return '1';
  else
    return '0';
}

char or(char a ,char b){
  if(a == '0' && b == '0')
    return '0';
  else
    return '1';
}

void print(char **ans){
  int i,j=0;
  int hed[8];
  char tel[8][10]={"x*y*z*","x*y*z","x*yz*","x*yz","xy*z*","xy*z","xyz*","xyz"};

  for(i=0 ;i<8 ;i++){
    if(ans[i][0] == '1'){
      if(j != 0)
	printf("+");
      printf("%s",tel[i]);
      j++;
    }
  }
  printf("\n");
}

void f_truth(char *f,char **ans){ //読み取った文字列のx,y,zを0と1に変換
  int i,j,k,l,m;
  int n=0;
  
  for(i=0 ;i<2 ;i++){
    for(j=0 ;j<2 ;j++){
      for(k=0 ;k<2 ;k++){
	m=0;
	for(l=0 ;l<100 ;l++){
	  if(f[l] == 0)
	    break;
	  switch(f[l]){
	    case 'x':
	      if(f[l+1] == '*'){
		ans[n][m]='0'+abs(i-1);
		l++;
	      }
	      else
		ans[n][m]='0'+i;
	      break;
	    case 'y':
	      if(f[l+1] == '*'){
		ans[n][m]='0'+abs(j-1);
		l++;
	      }
	      else
		ans[n][m]='0'+j;
	      break;
	    case 'z':
	      if(f[l+1] == '*'){
		ans[n][m]='0'+abs(k-1);
		l++;
	      }
	      else
		ans[n][m]='0'+k;
	      break;
	    case '+':
	      ans[n][m]='+';
	      break;
	  }
	  m++;
	}
	n++;
      }
    }
  }
}

int f_confirm(char **ans){ //ansの中にorがいくつあるか確かめる
  int i;
  int sum=0,leg;

  leg=strlen(ans[0]);
  for(i=0 ;i<100 ;i++){ 
    if(ans[0][i] == '+')
      sum++;
  }
  if(leg-sum == sum+1) //or演算子と数字の数がいい感じだと0を返す
    return 0;
  else
    return 1;
}

void f_and(char **ans){ //ansの中のand演算子だけを計算する
  int i,j;
  int n;
  char temp[N]={}; //ansに直接入れると隙間ができるため、tempを噛ませる

  while(f_confirm(ans) > 0){
    for(i=0 ;i<8 ;i++){
      n=0;
      for(j=0 ;j<N ;j++){
	if(ans[i][j] == 0)
	  break;
	switch(ans[i][j]){
	  case '0':
          case '1':
	    if(ans[i][j+1] == '0' || ans[i][j+1] == '1'){
	      temp[n]=and(ans[i][j],ans[i][j+1]);
	      j++;
	    }
	    else
	      temp[n]=ans[i][j];
	    break;
	  case '+':
	    temp[n]=ans[i][j];
	}
	n++;
      }
      strcpy(ans[i],temp); 
    }
  }
}

void f_or(char **ans){ //or演算子の計算
  int i,j;
  int n;
  char temp[N]={};

  while(strlen(ans[0]) != 1){
    for(i=0 ;i<8 ;i++){
      n=0;
      for(j=1 ;j<N ;j+=2){ //ans[1]から初めて両はしを計算
	if(ans[i][j] == 0)
	  break;
	temp[n]=or(ans[i][j-1],ans[i][j+1]);
	n++;	
      }
      strcpy(ans[i],temp);
    }
  }
}
  
  
int main(void){

  int i,j,k;
  int n=0;
  char f[N];
  char **ans;

  printf("f(x,y,z)= ");scanf("%s",f);
  usage(f);
  
  //ansのメモリ確保
  ans=malloc(sizeof(char *)*8);
  for(i=0 ;i<8 ;i++)
    ans[i]=malloc(sizeof(char)*N);
  
  //ansの初期化
  for(i=0 ;i<8 ;i++){
    for(j=0 ;j<N ;j++){
      ans[i][j]=0;
    }
  }
  
  f_truth(f,ans);

  f_and(ans);

  f_or(ans);
  
  //表示
  printf("\n主加法標準形へ展開すると\n");
  print(ans);
  
  free(ans);
  
  return 0;
}
