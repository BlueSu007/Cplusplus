#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
using namespace std;

int n ;
string a = " IVXLCDM" ;
map < int , int > value , I , V , X , L , C , D , M ;
map < char , int > cnt ;
map < char , map < int , int > * > link ;
map < int , string > strList ;
inline void init () ;
inline void add ( int x , int num ) ;

int main () {

    scanf ( "%d" , &n ) ;
    // cout << "ErrorPoint-1" << endl ;
    init () ;
    // cout << "ErrorPoint0" << endl ;

    for ( int i = 1 ; i <= n ; i++ ) {
        int tmp = i , now = 13 ;
        // cout << "ErrorPoint1" << endl ;
        while ( tmp ) {
            while ( tmp < value[now] ) {
                now-- ;
            }

            add ( now , tmp / value[now] ) ;
            // cout << "ErrorPoint2" << endl ;
            tmp %= value[now] ;
        }
        
        // for ( int i = 1 ; i <= 7 ; i++ ) {
            // if ( cnt[a[i]] ) {
                // printf ( "%c %d\n" , a[i] , cnt[a[i]] ) ;
            // }
        // }
        // cout << "ErrorPoint3" << endl ;
    }

    for ( int i = 1 ; i <= 7 ; i++ ) {
        if ( cnt[a[i]] ) {
            printf ( "%c %d\n" , a[i] , cnt[a[i]] ) ;
        }
    }

    return 0 ;
}

inline void init () {
    // cout << "BreakPoint1" << endl ;
    value[1] = 1 , value[2] = 4 , value[3] = 5 , value[4] = 9 ;
    value[5] = 10 , value[6] = 40 , value[7] = 50 , value[8] = 90 ; 
    value[9] = 100 , value[10] = 400 , value[11] = 500 , value[12] = 900 ;
    value[13] = 1000 ;

    // cout << "BreakPoint2" << endl ;
    I[1] = I[2] = I[4] = 1 ;
    V[2] = V[3] = 1 ;
    X[4] = X[5] = X[6] = X[8] = 1 ;
    L[6] = L[7] = 1 ;
    C[8] = C[9] = C[10] = C[12] = 1 ;
    D[10] = D[11] = 1 ;
    M[12] = M[13] = 1 ;

    // cout << "BreakPoint3" << endl ;
    link['I'] = &I ;
    // cout << "BreakPoint4" << endl ;
    link['V'] = &V ;
    link['X'] = &X ;
    link['L'] = &L ;
    link['C'] = &C ;
    link['D'] = &D ;
    link['M'] = &M ;
}

inline void add ( int x , int num ) {
    for ( int i = 1 ; i <= 7 ; i++ ) {
        cnt[a[i]] += ( ( *link[a[i]] ) [x] ) * num ;
    }
}
