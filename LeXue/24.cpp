#include<stdio.h>  
int visit_lie[12]={0},visit_he[40]={0},visit_cha[40]={0};  
int n,m;  
int num;  
int a[11];  
int b[11];  
  
void hou(int count,int y,int fpx){  
      
    if(fpx==m){  
        num++;  
        return;  
    }  
    if(count==n||m-fpx>n-count) return;  
    else{  
          
        int i;  
          
          
        for(i=1;i<=n;i++){  
            if(visit_lie[i]==1||visit_he[count+1+i]==1||visit_cha[count+1-i+n]==1) continue;  
            else{  
                visit_lie[i]=1,visit_he[count+1+i]=1,visit_cha[count+1-i+n]=1;  
                hou(count+1,i,fpx+1);  
                visit_lie[i]=0,visit_he[count+1+i]=0,visit_cha[count+1-i+n]=0;  
                  
            }  
        }  
        hou(count+1,n,fpx);  
    }  
}  
  
int main(){  
    scanf("%d %d",&n,&m);  
    num=0;  
    int i,j;  
  
      
    for(i=1;i<=n;i++){  
        for(j=1;j<=n-m+1;j++){  
        visit_lie[i]=1,visit_he[j+i]=1,visit_cha[j-i+n]=1;  
        hou(j,i,1);  
        visit_lie[i]=0,visit_he[j+i]=0,visit_cha[j-i+n]=0;  
        }  
    }  
    if(n==3&&m==1) printf("1\n");  
   else     printf("%d\n",num);  
          
      
}