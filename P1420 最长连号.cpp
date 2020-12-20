#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	
	int n,cnt=0,max=0;
	cin>>n;
	
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		if(a[i+1]-a[i]==1)	cnt++;
		else	cnt=0;
		
		if(cnt>max)		max=cnt;
	}
	
	cout<<max+1<<endl;
	
	return 0;
}
