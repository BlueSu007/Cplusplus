#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int a[8] ;
char c ;

int main () {

    while ( cin >> c ) {
        if ( c == '1' || c == 'Q' || c == 'A' || c == 'Z' ) {
            a[0]++ ;
        }
        else if ( c == '2' || c == 'W' || c == 'S' || c == 'X' ) {
            a[1]++ ;
        }
        else if ( c == '3' || c == 'E' || c == 'D' || c == 'C' ) {
            a[2]++ ;
        }
        else if ( c == '4' || c == 'R' || c == 'F' || c == 'V' 
               || c == '5' || c == 'T' || c == 'G' || c == 'B' ) {
            a[3]++ ;
        }        
        else if ( c == '6' || c == 'Y' || c == 'H' || c == 'N' 
               || c == '7' || c == 'U' || c == 'J' || c == 'M' ) {
            a[4]++ ;
        }        
        else if ( c == '8' || c == 'I' || c == 'K' || c == ',' ) {
            a[5]++ ;
        }        
        else if ( c == '9' || c == 'O' || c == 'L' || c == '.' ) {
            a[6]++ ;
        }        
        else if ( c == '0' || c == 'P' || c == ';' || c == '/' || c == '-' || c == '=' || c == '[' || c == ']' || c == 39 ) {
            a[7]++ ;
        }
    }

    for ( int i = 0 ; i < 8 ; i++ ) {
        cout << a[i] << endl ;
    }

    return 0 ;
}
