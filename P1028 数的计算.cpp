#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[1000 + 5];

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i / 2; j++){
			dp[i] += dp[j];
		}
		
		dp[i]++;
	}
	
	cout << dp[n] << endl;
	
	return 0;
}
