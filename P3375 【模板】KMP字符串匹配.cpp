#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 2000005
int kmp[LEN] ;
string mainArr , matchArr ;

int main () {

    cin >> mainArr >> matchArr ;
    kmp[0] = -1 ;
    int len1 = mainArr.size () , len2 = matchArr.size () ;

    int j = 0 ;
    for ( int i = 1 ; i < len2 ; i++ ) {
        while ( j && matchArr[i] != matchArr[j] ) {
            j = kmp[j] ;
        }
        
        if ( matchArr[i] == matchArr[j] ) {
            kmp[i + 1] = ++j ;
        }
    }

    j = 0 ;
    for ( int i = 0 ; i < len1 ; i++ ) {
        while ( j && mainArr[i] != matchArr[j] ) {
            j = kmp[j] ;
        }
        
        if ( mainArr[i] == matchArr[j] ) {
            j++ ;
        }

        if ( j == len2 ) {
            printf ( "%d\n" , i - len2 + 2 ) ;
        }
    }

    for ( int i = 1 ; i <= len2 ; i++ ) {
        printf ( "%d " , kmp[i] ) ;
    }

    return 0 ;
}
