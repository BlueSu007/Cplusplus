#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;

int t, n, m;
int a[100 + 5][100 + 5];
int f[10000 + 5], ans;

int main(){
	
	cin >> t >> n >> m;
	
	for(int i = 1; i <= t; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	
	ans = m;
	
	for(int i = 1; i <= t; i++){
		
		memset(f, ~0x7fffff, sizeof(f));
		f[ans] = ans;
		
		for(int j = 1; j <= n; j++){
			for(int k = ans; k >= a[i][j]; k--){
				f[k - a[i][j]] = max(f[k - a[i][j]], f[k] + a[i + 1][j] - a[i][j]);
			}
		}
		
		int maxn = 0;
		for(int i = 0; i <= ans; i++)
			maxn = max(maxn, f[i]);
			
		ans = maxn;
	}
	
	cout << ans << endl;
	
	return 0;
}
