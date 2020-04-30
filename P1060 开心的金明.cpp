#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
using namespace std;

int m, n;
int v[30000 + 5], w[30000 + 5];
int f[30000 + 5], r[30000 + 5];

int main(){
	
	cin >> m >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> v[i] >> w[i];
		r[i] = v[i] * w[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= v[i]; j--){
			if(j >= v[i])
				f[j] = max(f[j], f[j - v[i]] + r[i]);
		}
	}
	
	cout << f[m] << endl;
	
	return 0;
}
