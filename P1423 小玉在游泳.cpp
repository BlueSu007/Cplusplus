#include <iostream>
#include <cstdio>
#include <stdio.h>
using namespace std;

int main(){
	
	int n;
	scanf("%d",&n);
	
	double low=0,mid=0,high=0;
	
	if(n-150>0){
		low=0.4463*150;
		n-=150;
	}else{
		printf("%.1lf",0.4463*n);
		return 0;
	}
	
	if(n-250>0){
		mid=0.4663*250;
		n-=250;
	}else{
		printf("%.1lf\n",0.4663*n+low);
		return 0;
	}
	
	double ans=low+mid+(double)n*0.5663;
	printf("%.1lf\n",ans);
	
	return 0;
}
