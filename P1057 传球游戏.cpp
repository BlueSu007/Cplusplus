#include <iostream>
using namespace std;

int dp[101][101];

int main(){
	
	int n,m;
	cin>>n>>m;
	
	dp[0][0]=1;
	
	for(int j=1;j<=m;j++){
		for(int i=0;i<n;i++){
			dp[i][j]=dp[(i-1+n)%n][j-1]+dp[(i+1)%n][j-1];
		}
	}
	
	cout<<dp[0][m]<<endl;
	
	return 0;
}
