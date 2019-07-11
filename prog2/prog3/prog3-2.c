//The prey-predator model

#include <stdio.h>

#define N 10
#define M 2
#define MIN 0
#define MAX 3

int prey(int pry ,int prdt){
  
  if(pry == 0)
    return 0;
  else{
    if(prdt <= 1)
      return 2;
    else
      return 1;
  }
}

int predator(int pry ,int prdt){
  
  if(prdt == 0)
    return 0;
  else{
    if(pry == 0)
      return prdt-1;
    else if(pry == 1)
      return 1;
    else
      return 2;
  }  
}
  
int main(void){
    
  int i=0,j;
  int pop[N][M];
  int judg=0;
  
  printf("Enter prey, predator:");
  scanf("%d%d",&pop[0][0],&pop[0][1]);
  
  if(pop[0][0] < MIN || pop[0][0] > MAX || pop[0][1] < MIN || pop[0][1] > MAX){
    printf("Error\n");
    return 0;
  }
  
  while(judg != 1 ){
    printf("step %d   prey: %d   predator: %d\n",i,pop[i][0],pop[i][1]);
    i++;
    pop[i][0]=prey(pop[i-1][0] ,pop[i-1][1]);
    pop[i][1]=predator(pop[i-1][0] ,pop[i-1][1]);
    for(j=i-1 ;j>=0 ;j--){
      if(pop[i][0] == pop[j][0] && pop[i][1] == pop[j][1]){
	judg=1;
	break;
      }
    }
  }
  
  printf("step %d   prey: %d   predator: %d\n",j,pop[i][0],pop[i][1]);
  
  return 0;
}
