#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a[100 + 20], c[100 + 20], p, ans;

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	for(int i = 1; i <= n; i++)
		c[i] = c[i - 1] + a[i];
	
	p = c[n] / n;
	
	for(int i = 1; i < n; i++)
		if(p * i != c[i])
			ans++;
			
	cout << ans << endl;
	
	return 0;
}
