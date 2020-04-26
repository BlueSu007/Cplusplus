#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n, a, last, ans = 0;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a;
		
		if(a > last)
			ans += a - last;
			
		last = a;
	}
	
	cout << ans << endl;
	
	return 0;
}
