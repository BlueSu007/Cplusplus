#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int m, n;
int p[50000 + 5], t[50000 + 5];
int dp[50000 + 5];

int main(){
	
	cin >> m >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> p[i] >> t[i];
		
	for(int i = 1; i <= n; i++){
		for(int j = t[i]; j <= m; j++){
			dp[j] = max(dp[j], dp[j - t[i]] + p[i]);
		}
	}
	
	cout << dp[m] << endl;
	
	return 0;
}
