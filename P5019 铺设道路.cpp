#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5], n;
unsigned long long ans;

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	for(int i = 1; i <= n; i++)
		if(a[i] > a[i - 1])
			ans += a[i] - a[i - 1];
	
	cout << ans << endl;	
	
	return 0;
}
