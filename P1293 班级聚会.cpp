#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll ;
ll n , cost ;
ll people[50000 + 5] , dis[50000 + 5] , suf[50000 + 5] , val[50000 + 5] ;
ll sum , ans ;
char name[200 + 5][200 + 5] ;

int main () {

    int i = 1 ;
    while ( scanf ( "%lld %lld %s" , &people[i] , &dis[i] , name[i] ) != EOF ) {
        // ++ i ;
        cost += people[i] * dis[i] ;
        suf[i] = suf[i - 1] + people[i] ;
        sum += people[i] ;
        ++ i ;
    }

    val[i] = cost ;

    for ( int j = i - 1 ; j >= 1 ; -- j ) {
        val[j] = val[j + 1] + ( abs ( dis[j] - dis[j + 1] ) * ( sum - suf[j] ) ) - ( abs ( dis[j] - dis[j + 1] ) * suf[j] ) ;
        if ( val[j] < cost ) {
            cost = val[j] , ans = j ;
        }
    }

    printf ( "%s %lld" , name[ans] , cost ) ;

    return 0 ;
}
