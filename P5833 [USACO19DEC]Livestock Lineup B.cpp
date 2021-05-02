#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <vector>
using namespace std;

int n , flag , cnt ;
string s1 , s2 , c , a[10][10] , pam2[10] ;
map < string , int > pam1 ;
// map < int , string > pam2 ;
inline void init () ;

int main () {

	init () ;
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= 6 ; j++ ) {
			cin >> a[i][j] ;
		}
	}

	while ( cnt <= 43200 ) {
		flag = false , cnt++ ;
		for ( int i = 1 ; i <= n ; i++ ) {
			if ( abs ( pam1[a[i][1]] - pam1[a[i][6]] ) != 1 ) {
				flag = true ;
				break ;
			}
		}

		if ( ! flag ) {
			break ;
		}

		next_permutation ( pam2 + 1 , pam2 + 9 ) ;
		for ( int i = 1 ; i <= 8 ; i++ ) {
			pam1[pam2[i]] = i ;
		}
	}

	for ( int i = 1 ; i <= 8 ; i++ ) {
		cout << pam2[i] << endl ;
	}

	return 0 ;
}

inline void init () {
	pam1["Beatrice"] = 1 , pam1["Belinda"] = 2 , pam1["Bella"] = 3 , pam1["Bessie"] = 4 ;
	pam1["Betsy"] = 5 , pam1["Blue"] = 6 , pam1["Buttercup"] = 7 , pam1["Sue"] = 8 ;

	pam2[1] = "Beatrice" , pam2[2] = "Belinda" , pam2[3] = "Bella" , pam2[4] = "Bessie" ;
	pam2[5] = "Betsy" , pam2[6] = "Blue" , pam2[7] = "Buttercup" , pam2[8] = "Sue" ;
}
