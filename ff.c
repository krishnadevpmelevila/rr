#include <stdio.h>
struct alloc{
    int pname;
    int bname;
}al[100];
int bsize[10],psize[10],i;

void main(){
    int nb,np;
    printf("Enter no.of blocks: ");
    scanf("%d",&nb);
    printf("Enter no.of process: ");
    scanf("%d",&np);
    printf("Enter proccess size: ");
    for(i=0;i<np;i++){
        scanf("%d",&psize[i]);
    }
    printf("Enter Block size: ");
    for(i=0;i<nb;i++){
        scanf("%d",&bsize[i]);
    }

    for(i=0;i<np;i++){
        for(int j=0;j<nb;j++)
        {
            if(psize[i]<bsize[j]){
                al[i].pname=psize[i];
                al[i].bname=j+1;
                bsize[j]-=psize[i];
                break;
            }else{
                al[i].pname=-1;
            }
        }
        
    }
    printf("\nProccess no\tProccess size\tBlock no");
    for(int i=0;i<np;i++){
        printf("\n%d",i+1);
        if(al[i].pname!=-1){
            printf("\t\t%d",al[i].pname);
            printf("\t\t%d",al[i].bname);
        }else{
            printf("\t\tUNALLOCATED");
            printf("\tUNALLOCATED");
            
        }
        
        
    }

}
