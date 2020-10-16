#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a , b , leftn , rightn , t ;
int vis[10000000 + 5] ;

int main () {

    scanf ( "%d %d %d %d %d" , &a , &b , &leftn , &rightn , &t ) ;

    for ( int i = a ; i <= b ; i++ ) {
        for ( int j = 1 ; j < i ; j++ ) {
            for ( int k = 0 ; k < i ; k++ ) {
                if ( j == k ) {
                    continue ;
                }

                int x = 0 , t = 0 ;
                while ( x <= rightn ) {
                    if ( t % 2 == 0 ) {
                        x = x * i + j ;
                        t++ ;
                    }
                    else {
                        x = x * i + k ;
                        t++ ;
                    }

                    if ( x >= leftn && x <= rightn ) {
                        vis[x]++ ;
                    }
                }
            }
        }
    }

    for ( int i = leftn ; i <= rightn ; i++ ) {
        if ( vis[i] == t ) {
            printf ( "%d\n" , i ) ;
        }
    }

    return 0 ;
}
