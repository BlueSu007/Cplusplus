#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

string a , b , c ;
int ans , cnt_array ;

int main() {
	
	getline ( cin , a ) ; 
	getline ( cin , b ) ;
	
	int lena = a.size() ;
	int lenb = b.size() ;
	
	for ( int i = 0 ; i < lena ; i++ ) {
		a[i] = toupper ( a[i] ) ;
	}
	
	for ( int j = 0 ; j < lenb ; j++ ) {
		b[j] = toupper ( b[j] ) ; 
	}
	
    int j ;
	for ( int i = 0 ; i <= lenb - lena ; i++ ) {
		for ( j = 0 ; j < lena ; j++ ) {
			if ( b[j + i] != a[j] ) {
				break ;
			} 
			
			if ( i > 0 && b[i - 1] != ' ' ) {
				break ;
			}
		}

        if ( j == lena && ( b[j + i] == ' ' || j + i == lenb ) ) {
            ans++ ;
            if ( ans == 1 ) {
                cnt_array = i ;
            }
        }
	}
	
	if ( ans == 0 ) {
		cout << -1 << endl;
		exit(0) ;
	}
	
	cout << ans << " " << cnt_array << endl ;
	
	return 0 ;
}
