#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int doc[1000 + 5];
long long dp[1000 + 5];

int main(){
	
	int n;
	cin >> n;
	
	int cnt = 1;
	doc[cnt] = 2;
	for(int i = 3; i <= n; i += 2){
		int j;
		for(j = 2; j * j <= i; j++){
			if(i % j == 0)
				 break;
		}
		
		if(j * j <= i){
			continue;
		}
		
		cnt++;
		doc[cnt] = i;
	}
	
	dp[0] = 1;
	for(int i = 1; i <= cnt; i++){
		for(int j = doc[i]; j <= n; j++){
			dp[j] = dp[j] + dp[j - doc[i]];
		}
	}
	
	cout << dp[n] << endl;
	
	return 0;
} 
