#include <stdlib.h>
#include<stdio.h>
#include<string.h>
int n,max_size,head,i,j,track[20],size,order[20],mov,total;
void inputs(){
    printf("enter the number of track positions to be traversed ");
    scanf("%d",&n);
    printf("\n enter the max track size ");
    scanf("%d",&max_size);
    printf("\nenter the head position ");
    scanf("%d", &head);
    printf("enter the tracks\n");
    for(i=0;i<n;i++){
        scanf("%d",&track[i]);
    }
}
void calc(){
    track[n] = 0;
    track[n+1] = head;
    track[n+2] = max_size - 1;
    size = n+3;
    for(i=0;i<size;i++){
        for(j=0;j<size-i-1;j++){
            if(track[j]>track[j+1]){
                int temp = track[j];
                track[j] = track[j+1];
                track[j+1] = temp;
            }
        }
    }
    for(i=0;i<size;i++){
        if(track[i] == head){
            j=i;
            break;
        }
    }
    int count = 0;
    for(i=j+1;i<size;i++){
        order[count++] = track[i];
    }
    for(i=j-1;i>=0;i--){
        order[count++] = track[i];
    }
    for (i=0;i<count-1;i++){
        mov = abs(track[i-1]-track[i]); 
        total +=mov;
    }

}
void print(){
    printf("\n track order is ");
    for(i=0;i<size;i++){
        printf("%d\t",order[i]);
    }
    printf("\ntotal head movement = %d",total);
    printf("\naverage head movement = %d",total/n);
}
void main(){
    inputs();
    calc();
    print();
}