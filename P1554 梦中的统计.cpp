#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int js[15];

int main(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i=n;i<=m;i++)
		for(int j=i;j;j/=10)
			js[j%10]++;
			
	for(int i=0;i<=9;i++)
		cout<<js[i]<<" ";
	
	return 0;
}
