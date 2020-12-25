#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
using namespace std;

int n , m ;
double score ;
string stdAns , studentId , studentType , studentAns ;
map < int , char > pam ;
map < string , int > qwq ;
inline int twoChangeTen ( string s ) ;

int main () {

    // ios :: sync_with_stdio ( false ) ;
    cin >> n >> m >> stdAns ;
    score = 100.0 / m ;
    pam[8] = 'A' , pam[4] = 'B' , pam[2] = 'C' , pam[1] = 'D' ;
    qwq["10"] = 1 , qwq["01"] = 0 , qwq["00"] = qwq["11"] = -1 ;

    for ( int i = 1 ; i <= n ; i++ ) {
        int flag = false , id , type ;
        double ans = 0 ;
        cin >> studentId >> studentType ;
        id = twoChangeTen ( studentId ) , type = qwq[studentType] ;

        if ( id >= 1 && id <= 10000 ) {
            flag = true ;
        }

        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> studentAns ;
            if ( flag && stdAns[j - 1] == pam[twoChangeTen ( studentAns )] ) {
                ans += score ;
            }
        }

        if ( flag ) {
            cout << "ID: " << id << endl << "Type " ;
            if ( type == ! ( studentId[15] - '0' ) ) {
                cout << "Correct" << endl ;
            }
            else {
                cout << "Incorrect" << endl ;
            }
            printf ( "%.1lf" , ans ) ;
            cout << endl << endl ;
        }
        else {
            cout << "Wrong ID" << endl << endl ;
        }
    }

    return 0 ;
}

inline int twoChangeTen ( string s ) {
    int len = s.size () , i = 0 , ans = 0 ;
    while ( i < len ) {
        ans += ( s[len - i - 1] - '0' ) * pow ( 2 , i ) ;
        i++ ;
    }
    return ans ;
}
