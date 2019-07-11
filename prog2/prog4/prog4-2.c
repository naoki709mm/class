//Rule 90
#include <stdio.h>

#define N 100
#define CELL 100
#define ONE 50

void display(int array[CELL]){
  
  int i;
  
  for(i=0 ;i<CELL ;i++){
    if(array[i] == 0)
      printf("□");
    else
      printf("■");
  }
  printf("\n");
  
}

void update(int array[CELL] ,int input[CELL]){
  
  int i;
  
  for(i=0 ;i<CELL ;i++)
    array[i]=input[i];
}

void calculate_next(int array[CELL]){
  
  int i;
  int high,low;
  int ans[CELL];

  for(i=0 ;i<CELL ;i++){
    if(i == 0){
      high=i+1;
      low=CELL-1;
    }
    else if(i == CELL-1){
      high=0;
      low=i-1;
    }
    else{
      high=i+1;
      low=i-1;
    }
    ans[i]=(array[low]^array[i])^(array[i]^array[high]);
  } 
  
  update(array ,ans);
  
}

int main(void){
  
  int i;
  int array[CELL]={};
  
  array[ONE]=1;
  
  display(array);
  
  for(i=0 ;i<N ;i++){
    calculate_next(array);
    display(array);
  }
  
  return 0;
}
