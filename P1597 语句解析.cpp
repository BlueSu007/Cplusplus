#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map < char , char > pam ;
char a , b ;

int main () {

	pam['a'] = '0' , pam['b'] = '0' , pam['c'] = '0' ;
	
	while ( scanf ( "%c:=%c;" , &a , &b ) == 2 ) {
		if ( !isdigit(b) ) {
			pam[a] = pam[b] ;
		}
		else {
			pam[a] = b ;
		}
	}

	printf ( "%c %c %c" , pam['a'] , pam['b'] , pam['c'] ) ;

	return 0 ;
}
