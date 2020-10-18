#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
#include <string>
using namespace std;

struct node {
    string a , b ;
    int k ;
} AK[50000 + 5] ;

inline bool cmp ( node x , node y ) {
    return x.b > y.b ;
}

int n , m , x , y ;
string s ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> AK[i].a ;
        AK[i].k = i ;
        
        int len = AK[i].a.size () ;
        for ( int j = 0 ; j < len ; j++ ) {
            AK[i].b += toupper ( AK[i].a[j] ) ;
        }
    }

    sort ( AK + 1 , AK + 1 + n , cmp ) ;

    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( AK[j].k >= x && AK[j].k <= y ) {
                cout << AK[j].a << endl ;
                break ;
            }
        }
    }

    return 0 ;
}
