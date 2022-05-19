#include <stdio.h>
#include <stdlib.h>


int tph, philname[20], status[20], hungs, hu[20], cho;
int main()
{
  int i;
  printf("\n\nDINING PHILOSOPHER PROBLEM");
  printf("\nEnter the total no. of philosophers: ");
  scanf("%d",&tph);
  for(i=0;i<tph;i++)
  {
    philname[i] = (i+1);
    status[i] = 1;
  }
  printf("How Many are hungry?>");
  scanf("%d",&hungs);
  if(hungs == tph){
    printf("\n All are Hungry ..\nDeadlock");
  }
  else{
    for(i = 0; i < hungs;i++){
      printf("Enter philosopher %d position",(i+1));
      scanf("%d",&hu[i]);
      status[hu[i]] = 2;
    }
    do{
      printf("How many can eat at a time (1/2):");
      scanf("%d",&cho);
      switch(cho){
        case 1:
          one();
          break;
        case 2:
          two();
          break;
        case 3:exit(0);
        default:
          printf("Invalid option\n");
      }
    }while(1);
  }
}
  
one(){
  int pos=0,x,i;
  printf("\nAllow one philosopher to eat at a time\n");
  for(i=0;i<hungs;i++,pos++){
    printf("\nP %d is eating",philname[hu[pos]]);
    for(x = pos;x<hungs;x++)
      printf("\n P %d is waiting",philname[hu[x]]);
  }
}

two(){
  int i,j,s=0,t,r,x;
  printf("\n Allow two philosophers to eat at same time\n");
  for(i = 0; i < hungs; i++){
    for(j = i+1; j < hungs; j++){
      if(abs(hu[i]-hu[j]) >= 1&& abs(hu[i]-hu[j])!=4){
        printf("\n\ncombination %d \n", (s+1));
        t=hu[i];
        r=hu[j];
        s++;
        printf("\nP %d and P %d are granted to eat",philname[hu[i]],philname[hu[j]]);
        for(x = 0;x<hungs;x++){
          if((hu[x]!=t)&&(hu[x]!=r))
            printf("\n P %d is waiting",philname[hu[x]]);
        }
      }
    }
  }
}
