#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int m , bits[100] , vis[10] , len , sum ;
inline void getBit ( int x ) ;
inline bool ifRound ( int x ) ;

int main () {

    scanf ( "%d" , &m ) ;
    while ( ! ifRound ( ++m ) ) ;
    printf ( "%d" , m ) ;

    return 0 ;
}

inline void getBit ( int x ) {
    len = sum = 0 ;
    memset ( bits , 0 , sizeof ( bits ) ) ;

    while ( x ) {
        bits[++len] = x % 10 ;
        x /= 10 ;
    }

    reverse ( bits + 1 , bits + 1 + len ) ;
}

inline bool ifRound ( int x ) {
    int cnt = 1 ;
    getBit (x) ;
    memset ( vis , 0 , sizeof ( vis ) ) ;

    for ( int i = 1 ; i <= len ; i++ ) {
        if ( vis[bits[cnt]] || bits[cnt] == 0 ) {
            return false ;
        }

        vis[bits[cnt]]++ ;
        cnt = ( cnt + bits[cnt] ) % len ;

        if ( cnt == 0 ) {
            cnt = len ; 
        }
    }

    if ( cnt != 1 ) {
        return false ;
    }
    return true ;
}
