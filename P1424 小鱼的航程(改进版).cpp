#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	
	long long n,m,sum=0;
	cin>>n>>m;
	
	for(int i=1;i<=m;i++){
		if(n==8){
			n=1;
		}
		
		if(n==6||n==7){
			n++;
			continue;
		}
		
		sum+=250;
		n++;
	}
	
	cout<<sum<<endl;
	
	return 0;
}
