#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[6666][6666];

int main(){
	
	int n,x;
	cin>>n>>x;
	
	a[0][0]=a[1][0]=a[2][0]=a[2][1]=1;
	
	for(int i=3;i<=n;i++){
		for(int j=0;j<=x;j++){
			for(int k=0;k<=i-1&&j-k>=0;k++){
				a[i][j]=(a[i-1][j-k]+a[i][j])%10000;
			}
		}
	}
	
	cout<<a[n][x]<<endl;
	
	return 0;
}
