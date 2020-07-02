#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int n , m , x , y;
char c;
int a[1000 + 5][1000 + 5];
int ans[100000 + 5] , b[1000 + 5][1000 + 5];
const int dx[4] = { 0 , 0 , 1 , -1 };
const int dy[4] = { 1 , -1 , 0 , 0 };
inline bool check ( int x , int y );
inline void dfs ( int x , int y , int z , int step );

int main() {
	
	scanf ( "%d%d" , &n , &m );
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	
	memset ( b , -1 , sizeof(b) );
	
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &x , &y );
		if ( b[x][y] == -1 ) {
			dfs ( x , y , a[x][y] , i );
		}
		else {
			ans[i] = ans[b[x][y]];
		}
		
		if ( ans[i] == 0 ) {
			ans[i] = 1;
		}
	}
	
	for ( int i = 1 ; i <= m ; i++ ) {
		printf ( "%d\n" , ans[i] ); 
	}
	
	return 0; 
}

inline void dfs ( int x , int y , int z , int step ) {
	for ( int i = 0 ; i < 4 ; i++ ) {
		int fx = x + dx[i];
		int fy = y + dy[i];
		
		if ( fx >= 1 && fy >= 1 && fx <= n && fy <= n
		  && b[fx][fy] == -1 && a[fx][fy] == !z ) {
			b[fx][fy] = step;
			ans[step]++;
			dfs ( fx , fy , !z , step );
		}
	}
}

inline bool check ( int x , int y ) {
	for ( int i = 0 ; i < 4 ; i++ ) {
		int fx = x + dx[i];
		int fy = y + dy[i];
		if ( a[fx][fy] != a[x][y] ) {
			return true;
		}
	}
	
	return false;
}
