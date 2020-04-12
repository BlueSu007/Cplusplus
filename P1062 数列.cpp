#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
	
	long long k,n,sum=0,fn;
	cin>>k>>n;
	fn=n;
	
	//1.
	long long a[100],p=0;
	do{
		a[p++]=fn%2;
		fn/=2;
	}while(fn!=0);
	
	//2.
	long long t=1;
	for(int i=0;i<p;i++){
		sum+=a[i]*t;
		t*=k;
	}
	
	cout<<sum;
	
	return 0;
}
