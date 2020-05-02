#include <iostream>
#include <stdio.h>
using namespace std;
int a[2225]={6,2,5,5,4,5,6,3,7,6};
int main(){
	int n,count=0;
	cin>>n;
	n-=4;
	for(int i=10;i<2222;i++){
		a[i]=a[i/10]+a[i%10];
	} 
	for(int i=0;i<1111;i++){
		for(int j=0;j<1111;j++){
			if(a[i]+a[j]+a[i+j]==n){
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}
