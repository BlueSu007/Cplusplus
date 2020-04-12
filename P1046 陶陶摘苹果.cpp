#include <stdio.h>
int main(){
    int n,count=0;
    int a[10];
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&n);
	for(int i=0;i<10;i++){
		if(a[i]<=n+30){
			count++;
		}
	}
	printf("%d",count);
	return 0;
}
