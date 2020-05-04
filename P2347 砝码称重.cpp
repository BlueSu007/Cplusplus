#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int sum, w[6 + 5] = {0, 1, 2, 3, 5, 10, 20};
int a[6 + 5], dp[1000 + 5], ans;

int main(){
	
	for(int i = 1; i <= 6; i++){
		cin >> a[i];
		sum += a[i] * w[i];
	}
	
	dp[0] = 1;	
	for(int i = 1; i <= 6; i++){
		for(int j = 1; j <= a[i]; j++){
			for(int k = 1000; k >= 0; k--){
				if(dp[k])
					dp[k + w[i]] = 1;
			}
		}
	}
	
	for(int i = 1; i <= 1000; i++){
		if(dp[i])
			ans++;
	}
	
	cout << "Total=" << ans << endl;
	
	return 0;
}
