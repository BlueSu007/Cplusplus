#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

map < int , string > pam , apm ;
int n , flag1 , flag2 , flag3 ;
string s ;
inline void init () ;

int main () {

    init () ;
    scanf ( "%d" , &n ) ;

    if ( n == 0 ) {
        printf ( "zero" ) ;
        exit ( false ) ;
    }

    if ( n >= 1000 ) {
        cout << pam[n / 1000] << " thousand " ;
        n %= 1000 , flag1 = true ;
    }
    if ( n >= 100 ) {
        cout << pam[n / 100] << " hundred " ;
        n %= 100 , flag2 = true ;
    }
    if ( n >= 10 ) {
        if ( flag1 && !flag2 ) {
            printf ( "and " ) ;
        }
        if ( n <= 20 ) {
            cout << pam[n] ;
            exit ( false ) ;
        }

        cout << apm[n / 10] << " " ;
        n %= 10 , flag3 = true ;
    }
    if ( n != 0 ) {
        if ( !flag3 && ( flag1 || flag2 ) ) {
            printf ( "and " ) ;
        }
        cout << pam[n] ;
    }
    
    return 0 ;
}

inline void init () {
     pam[1] = "one" ,      pam[2] = "two" ,        pam[3] = "three" ,     pam[4] = "four" ,      pam[5] = "five" ;
     pam[6] = "six" ,      pam[7] = "seven" ,      pam[8] = "eight" ,     pam[9] = "nine" ,     pam[10] = "ten" ;
    pam[11] = "eleven" ,  pam[12] = "twelve" ,    pam[13] = "thirteen" , pam[14] = "fourteen" , pam[15] = "fifteen" ;
    pam[16] = "sixteen" , pam[17] = "seventeen" , pam[18] = "eighteen" , pam[19] = "nineteen" , pam[20] = "twenty" ;
     apm[3] = "thirty" ,   apm[4] = "fourty" ,     apm[5] = "fifty" ,     apm[6] = "sixty" ,     apm[7] = "seventy" ;
     apm[8] = "eighty" ,   apm[9] = "ninety" ;
}
