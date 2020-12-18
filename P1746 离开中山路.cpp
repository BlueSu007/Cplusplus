#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 1005
int n , map[LEN][LEN] , vis[LEN][LEN] , sx , sy , ex , ey ;
int que[LEN * LEN][4] , head , tail ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
char c ;
inline int bfs () ;

int main () {

	// freopen ( "P1746_1.in.txt" , "r" , stdin ) ;
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			// while ( scanf ( "%c" , &c ) && ! isdigit (c) ) ;
			scanf ( " %c" , &c ) ;
			if ( c == '0' ) {
				map[i][j] = 0 ;
			}
			else {
				map[i][j] = 1 ;
			}
		}
	}

	// for ( int i = 1 ; i <= n ; i++ ) {
	// 	for ( int j = 1 ; j <= n ; j++ ) {
	// 		printf ( "%d" , map[i][j] ) ;
	// 	}
	// 	cout << endl ;
	// }

	scanf ( "%d %d %d %d" , &sx , &sy , &ex , &ey ) ;

	printf ( "%d" , bfs () ) ;

	// for ( int i = 1 ; i < tail ; i++ ) {
	// 	printf ( "\n %d %d" , que[i][1] , que[i][2] ) ;
	// }

	return 0 ;
}

inline int bfs () {
	head = tail = vis[sx][sy] = 1 , tail++ ;
	que[head][1] = sx , que[head][2] = sy ;

	while ( head < tail ) {
		for ( int i = 0 ; i < 4 ; i++ ) {
			int fx = dx[i] + que[head][1] ;
			int fy = dy[i] + que[head][2] ;

			if ( fx < 1 || fy < 1 || fx > n || fy > n || vis[fx][fy] || map[fx][fy] ) {
				continue ;
			}

			que[tail][1] = fx , que[tail][2] = fy , que[tail][3] = que[head][3] + 1 ;
			tail++ , vis[fx][fy] = true ;

			if ( fx == ex && fy == ey ) {
				return que[tail - 1][3] ;
			}
		}

		head++ ;
	}

	return -1 ;
}
