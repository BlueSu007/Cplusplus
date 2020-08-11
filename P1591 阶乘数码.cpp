#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int a[5000 + 5] ;
int k , n , m ;
long long ans ;
inline void timeWith ( int x ) ;

int main() {
	
    cin >> k ;
    while ( k-- ) {
        ans = 0 ;
        scanf ( "%d %d" , &n , &m ) ;
        a[1] = 1 ;
        a[0] = 1 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            timeWith(i) ;
        } 
        
        bool flag = false ;
        for ( int i = a[0] ; i >= 1 ; i-- ) {
            if ( a[i] != 0 ) {
                flag = true ;
            }
            if ( flag ) {
                if ( a[i] == m ) {
                    ans++ ;
                }
                // printf ( "%d" , c[i] ) ;
            }
        }

        // cout << m << endl ;
        printf ( "%lld\n" , ans ) ;
        memset ( a , 0 , sizeof(a) ) ;
    }
	
	return 0 ;
}

inline void timeWith ( int x ) {
	for ( int i = 1 ; i < a[0] ; i++ ) {
        a[i] *= x ;
    }

    for ( int i = 1 ; i < a[0] ; i++ ) {
        if ( a[i] > 9 ) {
            a[i + 1] += a[i] / 10 ;
            a[i] %= 10 ;
        }
    }

    while ( a[a[0]] ) {
        a[a[0] + 1] += a[a[0]] / 10 ;
        a[a[0]] %= 10 ;
        a[0]++ ;
    }
}
