#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

char c ;
int n , x , y , digit , url , cnt , cnt1 , cnt2 , cnt3 ;
inline void func ( int kkksc03 ) ;
inline int read ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> c ;
        cnt1 = cnt2 = cnt3 = cnt = x = y = 0 ;
        if ( isdigit (c) ) {
            func ('0') ;
        }
        else {
            if ( c == 'a' ) {
                url = 1 ;
                func (c) ;
            }
            else if ( c == 'b' ) {
                url = 2 ;
                func (c) ;
            }
            else if ( c == 'c' ) {
                url = 3 ; 
                func (c) ;
            }
        }
    }

    return 0 ;
}

inline void func ( int kkksc03 ) {
    x = read ( c - kkksc03 ) , cnt1 = cnt ;
    y = read (0) , cnt2 = cnt ;

    if ( url == 1 ) {
        int tmp = abs ( x + y ) ;
        if ( x + y <= 0 ) {
            cnt3++ ;
        }

        while ( tmp ) {
            cnt3++ , tmp /= 10 ;
        }
        printf ( "%d+%d=%d\n%d\n" , x , y , x + y , cnt1 + cnt2 + cnt3 + 2 ) ;
    }
    if ( url == 2 ) {
        int tmp = abs ( x - y ) ;
        if ( x - y <= 0 ) {
            cnt3++ ;
        }

        while ( tmp ) {
            cnt3++ , tmp /= 10 ;
        }
        printf ( "%d-%d=%d\n%d\n" , x , y , x - y , cnt1 + cnt2 + cnt3 + 2 ) ;
    }
    if ( url == 3 ) {
        int tmp = abs ( x * y ) ;
        if ( x * y <= 0 ) {
            cnt3++ ;
        }

        while ( tmp ) {
            cnt3++ , tmp /= 10 ;
        }
        printf ( "%d*%d=%d\n%d\n" , x , y , x * y , cnt1 + cnt2 + cnt3 + 2 ) ;
    }
}

inline int read ( int x ) {
    int f = 1 ;
    char ch = getchar () ;
    cnt = 0 ;

    if ( x ) {
        cnt++ ;
    }

    while ( !isdigit (ch) ) {
        if ( ch == '-' ) {
            cnt++ ;
            f = -1 ;
        }
        ch = getchar () ;
    }

    while ( isdigit (ch) ) {
        x = x * 10 + ch - '0' ;
        ch = getchar () ;
        cnt++ ;
    }

    return x * f ;
}
