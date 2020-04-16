#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n,sum=0;
	int a[n+5];
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i])	sum++;
		}
	}
	
	cout<<sum<<endl;
	return 0;
}
