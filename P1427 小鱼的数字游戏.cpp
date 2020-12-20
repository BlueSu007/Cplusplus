#include<stdio.h>  
#include<stdlib.h>  

long long a[100]={1};  

int main()  
{   
	  int n,m,b,i=0,j;  
	
    while(a[i]!=0){
		i++;
		scanf("%d",&a[i]);
	}  
    
    for(j=i-1;j>=2;j--)
		printf("%d ",a[j]);

	  printf("%d",a[1]);  

    return 0;  
}  
