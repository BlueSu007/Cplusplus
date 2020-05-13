#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n, m, ans = INT_MAX;
int a[2000 + 5][2000 + 5];
int f[2000 + 5][2000 + 5];

int main(){
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[j][i];
			
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[i][j] = min(f[i - 1][j], j == 1 ? f[i - 1][m] : f[i - 1][j - 1]) + a[i][j];
	
	for(int i = 1; i <= m; i++)
		ans = min(ans, f[n][i]);
		
	cout << ans << endl;
	
	return 0;
}
