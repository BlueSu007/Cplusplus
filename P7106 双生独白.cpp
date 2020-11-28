#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

char c , x , y ;
int num ;
map < char , int > pam ;
map < int , char > apm ;
inline void init () ;
inline void changeCal () ;

int main () {

    scanf ( "%c" , &c ) ;
    printf ( "#" ) ;
    
    init () ;
    for ( int i = 1 ; i <= 3 ; i++ ) {
        changeCal () ;
    }

    return 0 ;
}

inline void init () {
    pam['0'] = 0 , pam['1'] = 1 , pam['2'] = 2 , pam['3'] = 3 , pam['4'] = 4 , pam['5'] = 5 ;
    pam['6'] = 6 , pam['7'] = 7 , pam['8'] = 8 , pam['9'] = 9 , pam['A'] = 10 , pam['B'] = 11 ;
    pam['C'] = 12 , pam['D'] = 13 , pam['E'] = 14 , pam['F'] = 15 ;
    
    apm[0] = '0' , apm[1] = '1' , apm[2] = '2' , apm[3] = '3' , apm[4] = '4' , apm[5] = '5' ;
    apm[6] = '6' , apm[7] = '7' , apm[8] = '8' , apm[9] = '9' , apm[10] = 'A' , apm[11] = 'B' ;
    apm[12] = 'C' , apm[13] = 'D' , apm[14] = 'E' , apm[15] = 'F' ;
}

inline void changeCal () {
    scanf ( "%c %c" , &x , &y ) ;
    num = pam[x] * 16 + pam[y] ;
    num = 255 - num ;

    printf ( "%c" , apm[num / 16] ) ;
    num %= 16 ;
    printf ( "%c" , apm[num] ) ;
}
