#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int c, h;
int a[5000 + 5];
int dp[50000 + 5];

int main(){
	
	cin >> c >> h;
	
	for(int i = 1; i <= h; i++)
		cin >> a[i];
		
	for(int i = 1; i <= h; i++){
		for(int j = c; j >= a[i]; j--){
			dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
			
			if(dp[c] == c){
				cout << dp[c] << endl;
				exit(0);
			}
		}
	}
	
	cout << dp[c] << endl;
	
	return 0;
}
