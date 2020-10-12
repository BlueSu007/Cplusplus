#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

struct kkksc03 {
    int num ;
    int id ;
} sum[10000 + 5] ;

inline bool cmp ( kkksc03 x , kkksc03 y ) {
    if ( x.num == y.num ) {
        return x.id < y.id ;
    }
    return x.num > y.num ;
}

int n , a , b ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &a , &b ) ;
        sum[i].id = i , sum[i].num = a * b ;
    }

    sort ( sum + 1 , sum + 1 + n , cmp ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d " , sum[i].id ) ;
    }

    return 0 ;
}
