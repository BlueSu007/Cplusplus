#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int s , t , w ;
string jam ;

int main () {

    scanf ( "%d %d %d" , &s , &t , &w ) ;
    cin >> jam ;

    for ( int i = 1 ; i <= 5 ; i++ ) {
        for ( int j = w - 1 ; j ; j-- ) {
            if ( jam[j] - 96 <= j - w + t ) {
                jam[j]++ ;
                for ( int k = j + 1 ; k < w ; k++ ) {
                    jam[k] = jam[k - 1] + 1 ;
                }

                cout << jam << endl ;
                break ;
            }
        }
    }

    return 0 ;
}
