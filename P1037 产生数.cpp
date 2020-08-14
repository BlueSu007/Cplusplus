#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std ;

char s[100 + 5] ;
int a[30 + 5] , num[30 + 5] , nextn[30 + 5][30 + 5] , vis[10 + 5] ;
int n , cnt ;
long long ans[30 + 5] ;
inline void mul();
inline void dfs ( int x , int y ) ;

int main() {
	
	// scanf ( "%s %d" , s , &n ) ;
    cin >> s >> n ;
	int len = strlen(s) ;
    ans[30] = 1 ;
	for ( int i = 0 ; i < len ; i++ ) {
		a[i + 1] = s[i] - '0' ;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		int x , y ;
		scanf ( "%d %d" , &x , &y ) ;
		nextn[x][++num[x]] = y ;
	}
	
	for ( int i = 1 ; i <= len ; i++ ) {
		cnt = 1 ;
		for ( int j = 1 ; j <= num[a[i]] ; j++ ) {
			dfs ( a[i] , nextn[a[i]][j] ) ;
		}
		
		memset ( vis , 0 , sizeof(vis) ) ;
		mul() ;
	}
	
	int firstnumber = 0 ;
	for ( ; ans[firstnumber] == 0 && firstnumber < 30 ; firstnumber++ ) ;
	for ( int i = firstnumber ; i <= 30 ; i++ ) {
		printf ( "%lld" , ans[i] ) ;
	}
	
	return 0 ;
}

inline void dfs ( int x , int y ) {
	vis[x] = 1 ;
	if ( vis[y] ) {
		return ;
	}
	cnt++ ;
	
	for ( int i = 1 ; i <= num[y] ; i++ ) {
		dfs ( y , nextn[y][i] ) ;
	}
}

inline void mul() {
	int carry = 0;
	for ( int i = 30 ; i ; i-- ) {
		ans[i] = ans[i] * cnt + carry ;
		carry = ans[i] / 10 ;
		ans[i] %= 10 ;
	} 
}
