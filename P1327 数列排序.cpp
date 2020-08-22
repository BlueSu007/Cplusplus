#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int n , a[100000 + 5] , b[100000 + 5] , cnt ;
map < int , int > pam ;

int main () {
    
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        b[i] = a[i] ;
        pam[a[i]] = i ;
    }

    sort ( b + 1 , b + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( a[i] != b[i] ) {
            cnt++ ;
        }
        
        pam[a[i]] = pam[b[i]] ;
        a[pam[b[i]]] = a[i] ;
    }

    printf ( "%d" , cnt ) ;

    return 0 ;
}
