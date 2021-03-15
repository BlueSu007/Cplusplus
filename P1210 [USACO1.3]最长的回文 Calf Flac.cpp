#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
using namespace std;

#define LEN 200005
char s[LEN] , a[LEN] ;
int pos[LEN] , cnt , maxn , posn ;
inline bool isreverse ( int startn , int len ) ;
inline void print ( int startn , int len ) ;

int main () {

    // freopen ( "P1210.8.in.txt" , "r" , stdin ) ;
    while ( cin.getline ( a , 85 ) ) {
        strcat ( s , a ) ;
        strcat ( s , "\n" ) ;
    }

    int len = strlen (s) ;
    for ( int i = 0 ; i < len ; i++ ) {
        if ( isupper ( s[i] ) ) {
            a[cnt] = tolower ( s[i] ) , pos[cnt++] = i ;
        }
        else if ( islower ( s[i] ) ) {
            a[cnt] = s[i] , pos[cnt++] = i ;
        }
    }

    for ( int i = 0 ; i < cnt ; i++ ) {
        for ( int j = maxn + 1 ; j < 2005 ; j++ ) {
            if ( isreverse ( i , j ) ) {
                maxn = j , posn = i ;
            }
        }
    }

    printf ( "%d\n" , maxn ) ;
    print ( posn , maxn ) ;

    return 0 ;
}

inline bool isreverse ( int startn , int len ) {
    if ( startn + len - 1 >= cnt ) {
        return false ;
    }
    for ( int i = 0 ; i < len ; i++ ) {
        if ( a[i + startn] != a[startn + len - i - 1] ) {
            return false ;
        }
    }
    return true ;
}

inline void print ( int startn , int len ) {
    for ( int i = pos[startn] ; i <= pos[startn + len - 1] ; i++ ) {
        printf ( "%c" , s[i] ) ;
    }
}
