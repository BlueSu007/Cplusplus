#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int v, n, c;
int k[10000 + 5], m[10000 + 5];
int f[10000 + 5];

int main(){
	
	cin >> v >> n >> c;
	
	for(int i = 1; i <= n; i++){
		cin >> k[i] >> m[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = c; j >= m[i]; j--){
			f[j] = max(f[j], f[j - m[i]] + k[i]);
		}
	}
	
	for(int i = 1; i <= c; i++){
		if(f[i] >= v){
			cout << c - i << endl;
			exit(0); 
		}
	}
	
	cout << "Impossible" << endl;
	
	return 0;
}
