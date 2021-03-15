#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 105
int a , b , c , vis[LEN][LEN][LEN] , ans[LEN * LEN * LEN] , cnt ;
inline void dfs ( int Aling , int Btianyi , int Chiyu ) ;

int main () {

    scanf ( "%d %d %d" , &a , &b , &c ) ;
    dfs ( 0 , 0 , c ) ;
    
    sort ( ans + 1 , ans + 1 + cnt ) ;
    for ( int i = 1 ; i <= cnt ; i++ ) {
        printf ( "%d " , ans[i] ) ;
    }

    return 0 ;
}

inline void dfs ( int Aling , int Btianyi , int Chiyu ) {
    if ( vis[Aling][Btianyi][Chiyu] ) {
        return ;
    }
    if ( Aling == 0 ) {
        ans[++cnt] = Chiyu ;
    }

    vis[Aling][Btianyi][Chiyu] = true ;
    if ( Aling < a ) {
        if ( Btianyi > ( a - Aling ) ) {
            dfs ( a , Btianyi - ( a - Aling ) , Chiyu ) ;
        }
        else {
            dfs ( Aling + Btianyi , 0 , Chiyu ) ;
        }

        if ( Chiyu > ( a - Aling ) ) {
            dfs ( a , Btianyi , Chiyu - ( a - Aling ) ) ;
        }
        else {
            dfs ( Aling + Chiyu , Btianyi , 0 ) ;
        }
    }

    if ( Btianyi < b ) {
        if ( Aling > ( b - Btianyi ) ) {
            dfs ( Aling - ( b - Btianyi ) , b , Chiyu ) ;
        }
        else {
            dfs ( 0 , Btianyi + Aling , Chiyu ) ;
        }

        if ( Chiyu > ( b - Btianyi ) ) {
            dfs ( Aling , b , Chiyu - ( b - Btianyi ) ) ;
        }
        else {
            dfs ( Aling , Btianyi + Chiyu , 0 ) ;
        }
    }

    if ( Chiyu < c ) {
        if ( Aling > ( c - Chiyu ) ) {
            dfs ( Aling - ( c - Chiyu ) , Btianyi , c ) ;
        }
        else {
            dfs ( 0 , Btianyi , Chiyu + Aling ) ;
        }

        if ( Btianyi > ( c - Chiyu ) ) {
            dfs ( Aling , Btianyi - ( c - Chiyu ) , c ) ;
        }
        else {
            dfs ( Aling , 0 , Chiyu + Btianyi ) ;
        }
    }
}
