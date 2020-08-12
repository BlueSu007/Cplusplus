#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int map[5][5] = { { 0 , 0 , 1 , 1 , 0 } , 
                  { 1 , 0 , 0 , 1 , 0 } , 
                  { 0 , 1 , 0 , 0 , 1 } , 
                  { 0 , 0 , 1 , 0 , 1 } , 
                  { 1 , 1 , 0 , 0 , 0 } } ;
int n , m , k , a[200 + 5] , b[200 + 5] , cnt1 , cnt2 ;

int main() {

    scanf ( "%d %d %d" , &n , &m , &k ) ;
    for ( int i = 0 ; i < m ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }
    for ( int i = 0 ; i < k ; i++ ) {
        scanf ( "%d" , &b[i] ) ;
    }

    for ( int i = 0 ; i < n ; i++ ) {
        cnt1 += map[a[i % m]][b[i % k]] ;
        cnt2 += map[b[i % k]][a[i % m]] ;
    }

    printf ( "%d %d" , cnt1 , cnt2 ) ;

    return 0 ;
}
