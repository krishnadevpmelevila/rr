#include<stdio.h>
#include<stdlib.h>
int main()
{
    int R[100],i,j,n,tm=0,initial,size,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&R[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    printf("Enter total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);
    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(R[j]>R[j+1])
            {
                int temp;
                temp=R[j];
                R[j]=R[j+1];
                R[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<R[i])
        {
            index=i;
            break;
        }
    }

    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            tm=tm+abs(R[i]-initial);
            initial=R[i];
        }
      
        tm=tm+abs(size-R[i-1]-1);
        initial = size-1;
        for(i=index-1;i>=0;i--)
        {
             tm=tm+abs(R[i]-initial);
             initial=R[i];
            
        }
    }

    else
    {
        for(i=index-1;i>=0;i--)
        {
            tm=tm+abs(R[i]-initial);
            initial=R[i];
        }
        
        tm=tm+abs(R[i+1]-0);
        initial =0;
        for(i=index;i<n;i++)
        {
             tm=tm+abs(R[i]-initial);
             initial=R[i];
            
        }
    }
    
    printf("Total head movement is %d",tm);
    return 0;
}
