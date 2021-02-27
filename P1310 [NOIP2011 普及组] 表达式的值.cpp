#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>
#include <string>
using namespace std;

#define MOD 10007
int n ;
string s ;
stack < int > number[2] ; 
stack < char > operatorX ;
inline void calculate () ;

int main () {

    // ios :: sync_with_stdio ( false ) ;
    cin >> n >> s ;
    s = '(' + s + ')' ;

    int len = s.size () ;
    for ( int i = 0 ; i < len ; i++ ) {
        if ( s[i] == '(' ) {
            operatorX.push ( s[i] ) ;
            if ( s[i + 1] != '(' ) {
                number[0].push (1) , number[1].push (1) ;
            }
        }
        else if ( s[i] == ')' ) {
            while ( operatorX.top () != '(' ) {
                calculate () ;
            }
            operatorX.pop () ;
        }
        else if ( s[i] == '+' ) {
            while ( operatorX.top () != '(' ) {
                calculate () ;
            }
            operatorX.push ( s[i] ) ;

            if ( s[i + 1] != '(' ) {
                number[0].push (1) , number[1].push (1) ;
            }
        }
        else if ( s[i] == '*' ) {
            while ( operatorX.top () == '*' ) {
                calculate () ;
            }
            operatorX.push ( s[i] ) ;

            if ( s[i + 1] != '(' ) {
                number[0].push (1) , number[1].push (1) ;
            }
        }
    }

    cout << number[0].top () << endl ;
    
    return 0 ;
}

inline void calculate () {
    int first0 , last0 , first1 , last1 , ans0 , ans1 ;
    char operate = operatorX.top () ;
    operatorX.pop () ;

    last0 = number[0].top () , number[0].pop () ;
    last1 = number[1].top () , number[1].pop () ;
    first0 = number[0].top () , number[0].pop () ;
    first1 = number[1].top () , number[1].pop () ;

    if ( operate == '+' ) {
        ans0 = first0 * last0 % MOD ;
        ans1 = ( first0 * last1 + first1 * last0 + first1 * last1 ) % MOD ;
    }
    else if ( operate == '*' ) {
        ans0 = ( first0 * last0 + first0 * last1 + first1 * last0 ) % MOD ;
        ans1 = first1 * last1 % MOD ;
    }

    number[0].push ( ans0 ) , number[1].push ( ans1 ) ;
    return ;
}
