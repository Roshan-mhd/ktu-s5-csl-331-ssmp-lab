#include <stdio.h>
int main()
{
    int n,bt[10],p[10],pro[10],wt[10],tat[10];
    float awt=0,atat=0;
    printf("Enter the number of processes: ");
    scanf("%d" ,&n);

    for(int i=0;i<n;i++)
    {
        pro[i]= i+1;
    }
    printf("Enter the burst and priority of each process: \n");

    for (int i=0; i<n; i++)
    {
        printf("p%d: ",i+1);
        scanf("%d %d" ,&bt[i],&p[i]);
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            int temp = p[j+1];
            p[j+1] = p[j];
            p[j] = temp;

            temp = pro[j+1];
            pro[J+1 = pro[j]];
            pro hs_==