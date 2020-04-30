#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
using namespace std;

int m, n;
int v[30000 + 5], w[30000 + 5];
int f[30000 + 5];

int main(){
	
	cin >> m >> n;
	
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	f[0] = 1;
	for(int i = 1; i <= m; i++){
		for(int j = n; j >= w[i]; j--){
			f[j] = f[j] + f[j - w[i]];
		}
	}
	
	cout << f[n] << endl;
	
	return 0;
}
