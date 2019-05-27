//Arrays and strings

#define N 100
#define M 100

#include <stdio.h>
#include <string.h>

int main(void){
  
  int i,j,k;
  int str[N];
  int max=0;
  char stc[N][M];
  
  for(i=0 ;i<10 ;i++){
    printf("Enter line %d:",i+1);
    fgets(stc[i] ,sizeof(stc[i]) ,stdin);
    str[i]=strlen(stc[i])-1;
    if(str[i] == 0)
      break;
    stc[i][str[i]]='\0';
    if(max < str[i])
      max=str[i];
  }
  
  for(j=0 ;j<max+6 ;j++)
    printf("#");
  printf("\n");
  
  for(j=0 ;j<i ;j++){
    printf("#  %s",stc[j]);
    for(k=str[j] ;k<max ;k++)
      printf(" ");
    printf("  #\n");
  }
  
  for(j=0 ;j<max+6 ;j++)
    printf("#");
  printf("\n");
  
  return 0;
}
