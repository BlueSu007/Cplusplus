#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

string QWQ , AWA , TAT ;
int n , a , x , y ;

int main () {

    cin >> n >> QWQ ;

    while ( n-- ) {
        cin >> a ;
        if ( a == 1 ) {
            cin >> AWA ;
            QWQ += AWA ;
            cout << QWQ << endl ;
        }
        else if ( a == 2 ) {
            cin >> x >> y ;
            TAT = QWQ.substr ( x , y ) ;
            QWQ = TAT ;
            cout << QWQ << endl ;
        }
        else if ( a == 3 ) {
            cin >> x >> AWA ;
            QWQ.insert ( x , AWA ) ;
            cout << QWQ << endl ;
        }
        else {
            cin >> AWA ;
            if ( QWQ.find (AWA) < QWQ.size () ) {
                cout << QWQ.find (AWA) << endl ;
            }
            else {
                cout << -1 << endl ;
            }
        }
    }

    return 0 ;
}
