#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#define ll long long
using namespace std ;

ll a , b , c , vis[30][30][30] ;
inline ll f ( ll a , ll b , ll c ) ;

int main () {

    while ( true ) {
        memset ( vis , 0 , sizeof (vis) ) ;
        scanf ( "%lld %lld %lld" , &a , &b , &c ) ;
        if ( a == -1 && b == -1 && c == -1 ) {
            break ;
        }
        printf ( "w(%lld, %lld, %lld) = %lld\n" , a , b , c , f ( a , b , c ) ) ;
    }


    return 0 ;
}

inline ll f ( ll a , ll b , ll c ) {
    if ( a <= 0 || b <= 0 || c <= 0 ) {
        return 1 ;
    }

    if ( a > 20 || b > 20 || c > 20 ) {
        if ( vis[20][20][20] ) {
            return vis[20][20][20] ;
        }
        vis[20][20][20] = f ( 20 , 20 , 20 ) ;
        return vis[20][20][20] ;
    }

    if ( vis[a][b][c] ) {
        return vis[a][b][c] ;
    }
    
    if ( a < b && b < c ) {
        vis[a][b][c] = f ( a , b , c - 1 ) + f ( a , b - 1 , c - 1 ) - f ( a , b - 1 , c ) ;
    }
    else {
        vis[a][b][c] = f ( a - 1 , b , c ) + f ( a - 1 , b - 1 , c ) + f ( a - 1 , b , c - 1 ) - f ( a - 1 , b - 1 , c - 1 ) ;
    }

    return vis[a][b][c] ;
}
