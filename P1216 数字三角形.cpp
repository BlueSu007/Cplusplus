#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int f[101][101], a[101][101];

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin >> a[i][j];
		}
	}
	
	f[1][1] = a[1][1];
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(f[n][i] > ans){
			ans = f[n][i];
		} 
	}
	
	cout << ans << endl;
	
	return 0;
}
