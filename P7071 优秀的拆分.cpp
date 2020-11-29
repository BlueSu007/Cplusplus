#include <bits/stdc++.h>
using namespace std;
int n , tmp[100000] ;
inline void dfs ( int step , int sum , int num ) ;

int main () {
    cin >> n ;
    if ( n % 2 == 1 ) {
        cout << -1 ;
        return 0 ;
    }
    dfs ( 0 , 0 , 1 ) ;
    cout << -1 ;
    return 0 ;
}

inline void dfs ( int step , int sum , int num ) {
    if ( step > 25 ) {
        return ;
    }

    if ( sum == n ) {
        for ( int i = step ; i >= 1 ; i-- ) {
            if ( !tmp[i] ) {
                continue ;
            }
            cout << tmp[i] << " " ;
        }
        exit ( false ) ;
    }

    dfs ( step + 1 , sum , num * 2 ) ;
    tmp[step + 1] = num * 2 ;
    dfs ( step + 1 , sum + num * 2 , num * 2 ) ;
    tmp[step + 1] = 0 ;
}
