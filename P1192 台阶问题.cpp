#include <iostream>
#include <cstdio>
#define MOD 100003
using namespace std;

int dp[1000100];

int main(){
	
	int n,k;
	cin>>n>>k;
	
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i>=j){
				dp[i]+=dp[i-j];
				dp[i]%=MOD;
			}
		}
	}
	
	cout<<dp[n]%MOD<<endl;
	
	return 0;
}
