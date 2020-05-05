#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int ans = -0x7fffff, n;
int a[500000 + 5];

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = max(a[i], a[i] + a[i - 1]);
		ans = max(a[i], ans);
	}
	
	cout << ans << endl;
	
	return 0;
}
