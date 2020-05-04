#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n, cnt = 0;
	cin >> n;
	
	int a, dp;
	for(int i = 1; i <= n; i++){
		cin >> a;
		if(a == 2)
			cnt++;
		else
			dp = min(dp + 1, cnt);
	}
	
	cout << dp << endl;
	
	return 0;
}
