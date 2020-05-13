#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define mian main
using namespace std;

int n, m, t;
int timen[200 + 5], money[200 + 5];
int dp[200 + 5][200 + 5];
//dp[money][time]

int mian(){
	
	cin >> n >> m >> t;
	
	for(int i = 1; i <= n; i++)
		cin >> money[i] >> timen[i];
	
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= money[i]; j--)
			for(int k = t; k >= timen[i]; k--)
				dp[j][k] = max(dp[j][k], dp[j - money[i]][k - timen[i]] + 1);
	
	cout << dp[m][t] << endl;
	
	return 0;
}
