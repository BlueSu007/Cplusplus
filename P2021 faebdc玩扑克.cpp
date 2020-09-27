#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int n , ans[1000000 + 5] , tmp[1000000 + 5] ;
queue < int > que ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        que.push (i) ;
    }

    for ( int i = 1 ; !que.empty () ; i++ ) {
        que.push ( que.front () ) ;
        que.pop () ;
        tmp[i] = que.front () ;
        que.pop () ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        ans[tmp[i]] = i ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d " , ans[i] ) ;
    }

    return 0 ;
}
