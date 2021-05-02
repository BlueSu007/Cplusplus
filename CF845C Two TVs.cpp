#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
#include <cstring>
#include <string>
using namespace std;

#define LEN 200005
int n , TV1 , TV2 ;
struct node {
    int leftn , rightn ;
    inline bool operator < ( const node &x ) const {
        if ( leftn == x.leftn ) {
            return rightn < x.rightn ;
        }
        return leftn < x.leftn ;
    }
} a[LEN] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &a[i].leftn , &a[i].rightn ) ;
    }

    sort ( a + 1 , a + 1 + n ) ;

    TV1 = TV2 = -1 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( a[i].leftn > TV1 ) {
           TV1 = a[i].rightn ;
        }
        else {
            if ( a[i].leftn <= TV1 && a[i].leftn > TV2 ) {
                TV2 = a[i].rightn ;
            }
            else {
                printf ( "NO\n" ) ;
                exit ( false ) ;
            }
        }
    }

    printf ( "YES\n" ) ;

    return 0 ;
}
