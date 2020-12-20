#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100 + 5][100 + 5], n, m, k;

int main(){
	
	int x, y;
	cin >> n >> m >> k;
	
	while(m != 0){
		cin >> x >> y;
		
		if(x - 1 >= 1 && y - 1 >= 1)	a[x - 1][y - 1] = 1;
		if(x - 1 >= 1)	a[x - 1][y] = 1;
		if(x - 1 >= 1 && y + 1 <= n)	a[x - 1][y + 1] = 1;
		
		if(y - 1 >= 1)	a[x][y - 1] = 1;
		a[x][y] = 1;
		if(y + 1 <= n)	a[x][y + 1] = 1;
		
		if(x + 1 <= n && y - 1 >= 1)	a[x + 1][y - 1] = 1;
		if(x + 1 <= n)	a[x + 1][y] = 1;
		if(x + 1 <= n && y + 1 <= n)	a[x + 1][y + 1] = 1;
		
		if(x - 2 >= 1)	a[x - 2][y] = 1;
		if(x + 2 <= n)	a[x + 2][y] = 1;
		if(y - 2 >= 1)	a[x][y - 2] = 1;
		if(y + 2 <= n)	a[x][y + 2] = 1;
		
		m--;
	}
	
	while(k != 0){
		cin >> x >> y;
		
		for(int i = x - 2; i <= x + 2; i++){
			for(int j = y - 2; j <= y + 2; j++){
				if(i < 1 || i > n || j < 1 || j > n)	continue;
				a[i][j] = 1;
			}
		}
		
		k--;
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 0)	cnt++;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
