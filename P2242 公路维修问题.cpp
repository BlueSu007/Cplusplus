#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long n , m , a[15000 + 5] , b[15000 + 5] , ans ;
inline bool cmp ( int x , int y ) {
    return x > y ;
}

int main ()  {

    scanf ( "%lld %lld" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &a[i] ) ;
    }

    ans = a[n] - a[1] + 1 ;

    for ( int i = 1 ; i < n ; i++ ) {
        b[i] = a[i + 1] - a[i] ;
    }

    sort ( b + 1 , b + n , greater < int > () ) ;

    for ( int i = 1 ; i < m ; i++ ) {
        ans = ans - b[i] + 1 ;
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}
