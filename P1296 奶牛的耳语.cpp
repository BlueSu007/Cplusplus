#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	
	int n,d,cnt=0;
	cin>>n>>d;
	
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d)		break;
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	return 0;
} 
