#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[15000];

int main(){
	
	int n,k,m;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>m;
		a[m]++;
	}
	
	int sum=0;
	for(int i=1;i<=15000;i++){
		if(a[i]!=0){
			sum++;
		}
		
		if(sum==k){
			cout<<i<<endl;
			return 0; 
		}
	}
	
	cout<<"NO RESULT"<<endl;
	
	return 0;
}
