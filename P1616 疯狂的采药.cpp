#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
using namespace std;

int m, n;
int t[30000 + 5], w[30000 + 5];
int f[300000 + 5];

int main(){
	
	cin >> m >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> t[i] >> w[i];
	
	for(int i = 1; i <= n; i++)
		for(int j = t[i]; j <= m; j++)
			f[j] = max(f[j], f[j - t[i]] + w[i]);
	
	cout << f[m] << endl;
	
	return 0;
}
