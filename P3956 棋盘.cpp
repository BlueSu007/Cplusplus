#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

long long n , m , x , y , url;
long long a[100 + 5][100 + 5] , map[100 + 5][100 + 5];
long long minn = 0x7fffffff;
const int dx[4] = { 0 , 0 , 1 , -1 };
const int dy[4] = { 1 , -1 , 0 , 0 };
inline void dfs ( long long x , long long y , long long coin , bool magic );

int main() {
	
	scanf ( "%d %d" , &m , &n );
	memset ( map , 0x7f , sizeof(map) );
	
	while ( n-- ) {
		scanf ( "%d %d %d" , &x , &y , &url );
		a[x][y] = url + 1;
	}
	
	dfs ( 1 , 1 , 0 , false );
	
	if ( minn == 0x7fffffff ) {
		minn = -1;
	}
	printf ( "%d" , minn );
	
	return 0;
}

inline void dfs ( long long x , long long y , long long coin , bool magic ) {

	if ( coin >= map[x][y] )
		return ;
	
	map[x][y] = coin;
	if ( x == m && y == m ) {
		minn = min ( minn , coin );
		return ;
	}
	
	for ( int i = 0 ; i < 4 ; i++ ) {
		
		int fx = x + dx[i];
		int fy = y + dy[i];
		if ( fx < 1 || fy < 1 || fx > m || fy > m )
			continue ;
			
		if ( a[fx][fy] ) {
			if ( a[fx][fy] == a[x][y] ) {
				dfs ( fx , fy , coin , false );
			}
			else {
				dfs ( fx , fy , coin + 1 , false );
			}
		}
		
		else {
			if ( !magic ) {
				a[fx][fy] = a[x][y];
				dfs ( fx , fy , coin + 2 , true );
				a[fx][fy] = 0;
			}
		}
	}
}
