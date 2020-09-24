#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

priority_queue < long long , vector < long long > , greater < long long > > que ;

int main () {

    long long tmp ;
    que.push (1) ;

    for ( int i = 1 ; i < 1500 ; i++ ) {
        tmp = que.top () ;
        que.push ( tmp * 2 ) ;
        que.push ( tmp * 3 ) ;
        que.push ( tmp * 5 ) ;

        while ( tmp == que.top () ) {
            que.pop () ;
        }
    }

    printf ( "The 1500'th ugly number is %lld.\n" , que.top () ) ;

    return 0 ;
}
