#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(string a,string b){
	return a+b<b+a;
}

int main(){
	
	int n;
	cin>>n;
	
	string a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n,cmp);
	
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	
	cout<<endl;
	
	return 0;
}
