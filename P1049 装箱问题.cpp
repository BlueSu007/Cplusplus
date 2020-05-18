#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int tmp[30 + 5];
int a[30 + 5][20000 + 5];

int main(){
	
	int n, m;
	cin >> m >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> tmp[i];
		
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(tmp[i] > j)
				a[i][j] = a[i - 1][j];
			else
				a[i][j] = max(a[i - 1][j], a[i - 1][j - tmp[i]] + tmp[i]);
				
	cout << m - a[n][m] << endl;
	
	return 0;
}
