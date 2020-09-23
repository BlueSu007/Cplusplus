#include<iostream>
#include<cstdio>
#include<cmath> 
#include<algorithm>
#include<cstring>
using namespace std;

int a1[20000] , b1[20000] , c[80000] ;

int main () {
	
	string a , b ;
	cin >> a >> b ; 
	
	if ( a < b && a.length() <= b.length() ) {
		cout << "-" ;
		swap ( a , b ) ;
	}
	else if ( a.length() < b.length () ) {
		cout << "-" ;
		swap ( a , b ) ;
	}
	
	int la , lb , i ;
	la = a.size () ; 
	lb = b.size () ;
	
	for ( i = 0 ; i <= la - 1 ; i++ ) {
		a1[i] = a[la - 1 - i ] - 48 ;
	}
	for ( i = 0 ; i <= lb - 1 ; i++ ) {
		b1[i] = b[lb - 1 - i] - 48 ;
	}
	
	for ( i = 0 ; i <= 19999 ; i++ ) {
		c[i] = a1[i] - b1[i] ;
	}
	for ( i = 0 ; i <= 19999 ; i++ ) {
		if ( c[i] < 0 ) {
			c[i + 1]-- ;
			c[i] = c[i] + 10 ;
		}
	}
	
	i = 19999 ;
	while ( c[i] == 0 && i > 0 ) {
		i-- ;
	}
	
	for ( ; i >= 0 ; i-- ) {
		cout << c[i] ;
	}
	
	return 0 ;
}
