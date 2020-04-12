#include <stdio.h>

int main(){
    
	int l,m,start,stop,count=0;
	scanf("%d%d",&l,&m);
	
	int a[l+1];
	for(int i=0;i<=l;i++){
		a[i]=1;
	}
	
	for(int i=0;i<m;i++){
		scanf("%d%d",&start,&stop);
		
		for(int j=start;j<=stop;j++){
			a[j]=0;
		}
	}
	
	for(int i=0;i<=l;i++){
		if(a[i]!=0){
			count++;
		}
	}
	
	printf("%d",count);
	
	return 0;
	
}
