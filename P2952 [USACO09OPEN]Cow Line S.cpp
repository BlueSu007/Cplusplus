#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

int n , x , cnt ;
deque < int > que ;
char c , a[100] ;

int main () {
	
	ios::sync_with_stdio ( false ) ;
	cin >> n ;
	while ( n-- ) {
		cin >> c ;
		if ( c == 'A' ) {
			cin >> c ;
			if ( c == 'L' ) {
				cnt++ ;
				que.push_front (cnt) ;
			}
			else {
				cnt++ ;
				que.push_back (cnt) ;
			}
		}
		else if ( c == 'D' ) {
			cin >> c >> x ;
			if ( c == 'L' ) {
				while ( x-- ) {
					que.pop_front () ;
				}
			}
			else {
				while ( x-- ) {
					que.pop_back () ;
				}
			}
		}
	}
	
	while ( !que.empty () ) {
		cout << que.front () << endl ;
		que.pop_front () ;
	}
	
	return 0 ;
}
