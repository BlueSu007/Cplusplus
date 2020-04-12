#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int dp[110][110],a[110],n,m;

int main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	dp[0][0]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=min(j,a[i]);k++){
				dp[i][j]+=dp[i-1][j-k]%1000007;
			}
		}
	}
	
	cout<<dp[n][m]%1000007<<endl;
	
	return 0;
}
