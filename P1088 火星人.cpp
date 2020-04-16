#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1000100];

int main(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int j=1;j<=m;j++){
		next_permutation(a+1,a+1+n);
	}
	
	for(int k=1;k<=n;k++){
		cout<<a[k]<<" ";
	}
	
	return 0;
}
