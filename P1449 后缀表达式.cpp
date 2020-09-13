#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

stack < int > st ;
char c ;
int x , y , z ;

int main () {

    while ( c != '@' ) {
        c = getchar () ;
        if ( c == '+' ) {
            x = st.top () , st.pop () ;
            y = st.top () , st.pop () ;
            st.push ( x + y ) ;
        }
        else if ( c == '-' ) {
            x = st.top () , st.pop () ;
            y = st.top () , st.pop () ;
            st.push ( y - x ) ;
        }
        else if ( c == '*' ) {
            x = st.top () , st.pop () ;
            y = st.top () , st.pop () ;
            st.push ( x * y ) ;
        }
        else if ( c == '/' ) {
            x = st.top () , st.pop () ;
            y = st.top () , st.pop () ;
            st.push ( y / x ) ;
        }
        else if ( c == '.' ) {
            st.push (z) ;
            z = 0 ;
        }
        else {
            z = z * 10 + c - '0' ;
        }
    }

    printf ( "%d" , st.top () ) ;

    return 0 ;
}
