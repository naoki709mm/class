//multiplication table

#include <stdio.h>

int main(void){
  
  int i;
  int num;
  
  printf("Which multiplication table do you want to see? Enter a number between 1 and 9:\n");
  scanf("%d",&num);  
  
  while(num != 0){
    if(num < 0 || num > 9){
      printf("Error\n");
    }
    else if(num >0 || num < 9){
      for(i=0 ;i<11 ;i++){
	printf("%d*%d=%d\n",num,i,num*i);
      }
    }
    printf("Which multiplication table do you want to see? Enter a number between 1 and 9:\n");
    scanf("%d",&num);
  }
  
  return 0;
}
