#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int lena , lenb ;
char c ;
int maze[6][6] = { { 0 , 0 , 0 , 0 , 0 , 0 } ,
                   { 0 , 5 , -1 , -2 , -1 , -3 } , 
                   { 0 , -1 , 5 , -3 , -2 , -4 } , 
                   { 0 , -2 , -3 , 5 , -2 , -2 } , 
                   { 0 , -1 , -2 , -2 , 5 , -1 } , 
                   { 0 , -3 , -4 , -2 , -1 , 0 } } ;
int dp[100 + 5][100 + 5] , a[100 + 5] , b[100 + 5] ;

int main () {

    scanf ( "%d" , &lena ) ;
    for ( int i = 1 ; i <= lena ; i++ ) {
        cin >> c ;
        if ( c == 'A' ) {
            a[i] = 1 ;
        }
        else if ( c == 'C' ) {
            a[i] = 2 ;
        }
        else if ( c == 'G' ) {
            a[i] = 3 ;
        }
        else if ( c == 'T' ) {
            a[i] = 4 ;
        }
    }

    scanf ( "%d" , &lenb ) ;
    for ( int i = 1 ; i <= lenb ; i++ ) {
        cin >> c ;
        if ( c == 'A' ) {
            b[i] = 1 ;
        }
        else if ( c == 'C' ) {
            b[i] = 2 ;
        }
        else if ( c == 'G' ) {
            b[i] = 3 ;
        }
        else if ( c == 'T' ) {
            b[i] = 4 ;
        }
    }

    for ( int i = 1 ; i <= lena ; i++ ) {
        for ( int j = 1 ; j <= lenb ; j++ ) {
            dp[i][j] = INT_MIN ;
        }
    }

    for ( int i = 1 ; i <= lena ; i++ ) {
        dp[i][0] = dp[i - 1][0] + maze[a[i]][5] ;
    }
    for ( int j = 1 ; j <= lenb ; j++ ) {
        dp[0][j] = dp[0][j - 1] + maze[5][b[j]] ;
    }

    for ( int i = 1 ; i <= lena ; i++ ) {
        for ( int j = 1 ; j <= lenb ; j++ ) {
            dp[i][j] = max ( dp[i][j] , dp[i - 1][j] + maze[a[i]][5] ) ;
            dp[i][j] = max ( dp[i][j] , dp[i][j - 1] + maze[5][b[j]] ) ;
            dp[i][j] = max ( dp[i][j] , dp[i - 1][j - 1] + maze[a[i]][b[j]] ) ;
        }
    }

    printf ( "%d" , dp[lena][lenb] ) ;

    return 0 ;
}
