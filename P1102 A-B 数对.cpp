#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

map <long long, long long> m;
long long n, a[200000 + 5], c;

int main(){
	
//	freopen("P1102_3.in.txt", "r", stdin);
	cin >> n >> c;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		m[a[i]]++;
		a[i] -= c;
	}
	
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		ans += m[a[i]];
	
	cout << ans << endl;
	
	return 0;
} 
