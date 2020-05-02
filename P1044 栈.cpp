#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a[20 + 5][20 + 5];

int main(){
	
	cin >> n;
	
	for(int j = 0; j <= n; j++){
		for(int i = n - j; i >= 0; i--){
			if(i == n && j == 0)
				a[i][j] = 1;
			else if(j == 0)
				a[i][j] = a[i + 1][j];
			else if(i == n - j)
				a[i][j] = a[i][j - 1];
			else
				a[i][j] = a[i + 1][j] + a[i][j - 1];
		}
	}
	
	cout << a[0][n];
	
	return 0;
}
