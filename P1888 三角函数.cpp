#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int gcd(int a,int b);

int main(){
	
	int a[3];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	
	sort(a,a+3);
	
	int gcdn=__gcd(a[0],a[2]);
	cout<<a[0]/gcdn<<"/"<<a[2]/gcdn<<endl;
	
	return 0;
}
