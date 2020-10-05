#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , ans , cnt , a[5000 + 5] ;
int syear , smonth , sday , shour , sminute ;
int eyear , emonth , eday , ehour , eminute ;
int month[13] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 31 , 30 } ;

inline void input () ;
inline void work () ;
inline void output () ;

inline bool isleap ( int x ) ;
inline void yearToDay () ;
inline void monthToDay () ;
inline void dayToMinute () ;

int main () {

    input () ;
    work () ;
    output () ;

    return 0 ;
}

inline void input () {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++  ) {
        scanf ( "%d" , &a[i] ) ;
    }

    sort ( a + 1 , a + 1 + n ) ;

    scanf ( "%d-%d-%d-%d:%d" , &syear , &smonth , &sday , &shour , &sminute ) ;
    scanf ( "%d-%d-%d-%d:%d" , &eyear , &emonth , &eday , &ehour , &eminute ) ;
}

inline void work () {
    yearToDay () ;
    monthToDay () ;
    dayToMinute () ;
}

inline void output () {
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( cnt >= a[i] ) {
            ans++ , cnt -= a[i] ;
        }
        else {
            break ;
        }
    }

    printf ( "%d" , ans ) ;
}

inline bool isleap ( int x ) {
    if ( x % 4 == 0 ) {
        if ( x % 100 == 0 ) {
            if ( x % 400 == 0 ) {
                return true ;
            }
            else {
                return false ;
            }
        }
        else {
            return true ;
        }
    }
    else {
        return false ;
    }
}

inline void yearToDay () {
    for ( int i = syear ; i < eyear ; i++ ) {
        if ( isleap (i) ) {
            cnt += 366 ;
        }
        else {
            cnt += 365 ;
        }
    }
}

inline void monthToDay () {
    for ( int i = 1 ; i < smonth ; i++ ) {
        if ( isleap (syear) && i == 2 ) {
            cnt -= ( month[i] + 1 ) ;
        }
        else {
            cnt -= month[i] ;
        }
    }

    for ( int i = 1 ; i < emonth ; i++ ) {
        if ( isleap (eyear) && i == 2 ) {
            cnt += ( month[i] + 1 ) ;
        }
        else {
            cnt += month[i] ;
        }
    }
}

inline void dayToMinute () {
    cnt = ( cnt - sday + eday ) * 24 * 60 ;
    cnt = cnt - ( 60 * shour + sminute ) + ( 60 * ehour + eminute ) ;
}
