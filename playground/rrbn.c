#include<stdio.h>
int i, atat, awt ,n,wt[20],trt[20],bt[20],temp=0,ct[20],max=0,t,j;

void inputs(){
    printf("enter the number of processes");
    scanf("%d",&n);
    printf("enter time slice");
    scanf("%d",&t);
    printf("enter burst times \n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        ct[i]=bt[i];
    }
}

void trt_calc(){
    max = bt[0];
    for ( i = 1; i < n; i++)
    { if(bt[i]>max){
        max = bt[i];}
    }

    for(j=0; j<(max/t)+1;j++){
        for ( i = 0; i < n; i++)
        {

        if(bt[i]!=0){
            if (bt[i] <=t){
                trt[i] = temp +bt[i];
                temp = temp + bt[i];
                bt[i] = 0;
            }else{
            bt[i] = bt[i] - t;
            temp = temp +t;
        }
        }

    }
}
    
}


void calc_wt(){
    for(i=0;i<n;i++){
        wt[i]= trt[i]-ct[i];
        atat += trt[i];
        awt+=wt[i];
    }
}

void printTable() {
  printf("\tProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
  for (int i = 0; i < n; i++) {
    printf("\tP%d\t\t%d\t\t%d\t\t%d \n", i , ct[i], wt[i], trt[i]);
  }
}



void main(){
    inputs();
    trt_calc();
    calc_wt();
    printTable();

}