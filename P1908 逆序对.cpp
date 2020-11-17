#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[500000 +  5] , b[500000 + 5] , c[500000 + 5] , tree[500000 + 5] ;
long long ans ;
inline void discretization () ;
inline int lowbit ( int k ) ;
inline void update ( int x , int k ) ;
inline int sum ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        b[i] = a[i] ;
    }

    discretization () ;

    for ( int i = 1 ; i <= n ; i++ ) {
        update ( c[i] , 1 ) ;
        ans += i - sum ( c[i] ) ;
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}

inline void discretization () {
    sort ( b + 1 , b + 1 + n ) ;
    int tmp = unique ( b + 1 , b + 1 + n ) - ( b + 1 ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        c[i] = lower_bound ( b + 1 , b + tmp + 1 , a[i] ) - b ;
    }
}

inline int lowbit ( int k ) {
    return k & -k ;
}

inline void update ( int x , int k ) {
    while ( x <= n )  {
        tree[x] += k ;
        x += lowbit (x) ;
    }
}

inline int sum ( int x ) {
    int ans = 0 ;
    while ( x > 0 ) {
        ans += tree[x] ;
        x -= lowbit (x) ;
    }
    return ans ;
}
