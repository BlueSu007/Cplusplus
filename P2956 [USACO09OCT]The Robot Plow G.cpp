#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , k , sx , sy , ex , ey;
int a[240 + 5][240 + 5] , sum;

int main() {
	
	scanf ( "%d %d %d" , &n , &m , &k );
	
	while ( k-- ) {
		scanf ( "%d %d %d %d" , &sx , &sy , &ex , &ey ); 
		for ( int i = sx ; i <= ex ; i++ ) {
			for ( int j = sy ; j <= ey ; j++ ) {
				if ( !a[i][j] ) {
					sum++;
					a[i][j] = 1;
				}
			}
		} 
	}
	
	printf ( "%d\n" , sum );
	
	return 0;
}
