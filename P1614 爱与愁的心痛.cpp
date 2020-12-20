#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n,m,a[100100];

int main(){
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int cnt=0,minn=0x7fffffff;
	for(int i=1;i<=n-m+1;i++){
		for(int j=1;j<=m;j++){
			cnt+=a[i+j-1];
		}
		if(cnt<minn)	minn=cnt;
		cnt=0;
	}
	
	cout<<minn<<endl;
	
	return 0;
}
