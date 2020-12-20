#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5] , n , x , len , ans[100000 + 5] ;
inline void push ( int x ) ;
inline void pop () ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &x ) ;
        push (x) ;
        // for ( int i = 1 ; i <= len ; i++ ) {
        //     printf ( "%d " , a[i] ) ;
        // }
        // printf ( "\n" ) ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        ans[i] = a[1] ;
        pop () ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d " , ans[i] ) ;
    }

    return 0 ;
}

inline void push ( int x ) {
    int son , tmp ;
    len++ ;

    a[len] = x ;
    son = len ;
    while ( son != 1 && ( a[son / 2] > a[son] ) ) {
        tmp = a[son / 2] ;
        a[son / 2] = a[son] ;
        a[son] = tmp ;
        son /= 2 ;
    }
}

inline void pop () {
    int parent = 1 , son , tmp ;
    a[1] = a[len] ;
    len-- ;

    while ( parent * 2 <= len ) {
        if ( ( parent * 2 + 1 > len ) || ( a[parent * 2] < a[parent * 2 + 1] ) ) {
            son = parent * 2 ;
        }
        else {
            son = parent * 2 + 1 ;
        }

        if ( a[parent] > a[son] ) {
            tmp = a[parent] ;
            a[parent] = a[son] ;
            a[son] = tmp ;
            parent = son ;
        }
        else {
            return ;
        }
    }
}
