#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n, t, ans = 0;
	cin >> n >> t;
	
	int a[n + 5];
	cin >> a[1];
	
	for(int i = 2; i <= n; i++){
		cin >> a[i];
		
		if(a[i - 1] + t < a[i])
			ans += t;
		else
			ans += a[i] - a[i - 1];
	}
	
	cout << ans + t << endl;
	
	return 0;
}
