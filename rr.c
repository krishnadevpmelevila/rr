#include <stdio.h>
int main(){
 int i,j,m,n,time,remain,flag=0,ts;
 int sum_wait=0 sum_turnaround=0,at[10],bt[10],rt[10];
 printf("Enter no.of processes: ")
 scanf("%d",&n);
 remain = n;
 for(i=0;i<n;i++){
 	printf("Enter arrival time and burst time for process P %d",i+1);
 	scanf("%d",&at[i]);
 	scanf("%d",&bt[i]);
 	rt[i]=bt[i];
 	
 }
 
 printf("Enter Quantam time: ")
 scanf("%d",&ts);
 for(time=0;i=0;remain!=0){
 	if(rt[i]<=ts && rt[i]>0){
 	time+=rt[i];
 	rt[i]=0;
 	flag=1;
 	}else if(rt[i]>0){
 		rt[i]-=ts;
 		time+=ts;
 	}
 	if(rt[i]==0&&flag==1){
 		remain--;
 		sum_wait+=time-at[i];
 		sum_turnaround+=time-at[i];
 		flag=0;
 	}
 	if(i==n-1){
 		i=0;
 	}
 	else if(at[i=1]<=time){
 		i++;
 	}
 	else{
 		i=0;
 	}
 	
 	print("\nAverage waiting time = %d\n",sum_wait/n);
 	print("\nTotal turnaround time = %d\n",sum_turnaround/n);
 }
}
