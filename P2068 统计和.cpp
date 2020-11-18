#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , q , cnt , x , y , pos ;
int leftson[200000 + 5] , rightson[200000 + 5] , leftn[200000 + 5] , rightn[200000 + 5] ;
long long k , a[100000 + 5] , sum[200000 + 5] ;
char op ;
inline void build ( int k , int leftbound , int rightbound ) ;
inline void modify ( int k , int x , long long m ) ;
inline long long query ( int k , int leftbound , int rightboud ) ;

int main () {

    scanf ( "%d %d" , &n , &q ) ;
    build ( ++cnt , 1 , n ) ;

    for ( int i = 1 ; i <= q ; i++ ) {
        // scanf ( "%c" , &op ) ;
        cin >> op ;
        if ( op == 'x' ) {
            scanf ( "%d %lld" , &pos , &k ) ;
            modify ( 1 , pos , k ) ;
        }
        else if ( op == 'y' ) {
            scanf ( "%d %d" , &x , &y ) ;
            printf ( "%lld\n" , query ( 1 , x , y ) ) ;
        }
    }

    return 0 ;
}

inline void build ( int k , int leftbound , int rightbound ) {
    leftn[k] = leftbound ;
    rightn[k] = rightbound ;
    if ( leftbound == rightbound ) {
        sum[k] = a[leftn[k]] ;
        return ;
    }

    int mid = ( leftn[k] + rightn[k] ) / 2 ;
    leftson[k] = ++cnt ;
    build ( cnt , leftn[k] , mid ) ;

    rightson[k] = ++cnt ;
    build ( cnt , mid + 1 , rightn[k] ) ;
    sum[k] = sum[leftson[k]] + sum[rightson[k]] ;
}

inline void modify ( int k , int x , long long m ) {
    if ( leftn[k] == rightn[k] ) {
        sum[k] += m ;
        return ;
    }

    int mid = ( leftn[k] + rightn[k] ) / 2 ;
    if ( x <= mid ) {
        modify ( leftson[k] , x , m ) ;
    }
    else {
        modify ( rightson[k] , x , m ) ;
    }

    sum[k] = sum[leftson[k]] + sum[rightson[k]] ;
}

inline long long query ( int k , int leftbound , int rightbound ) {
    if ( leftbound <= leftn[k] && rightn[k] <= rightbound ) {
        return sum[k] ;
    }

    int mid = ( leftn[k] + rightn[k] ) / 2 ;
    long long ans = 0 ;

    if ( leftbound <= mid ) {
        ans += query ( leftson[k] , leftbound , rightbound ) ;
    }
    if ( mid + 1 <= rightbound ) {
        ans += query ( rightson[k] , leftbound , rightbound ) ;
    }

    return ans ;
}
