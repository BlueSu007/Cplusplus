#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

string a[20 + 5];
int vis[20 + 5] , len , n;
inline int check ( string a , string b );
inline void dfs ( string s , int size );

int main() {
	
	cin >> n;
	for ( int i = 0 ; i <= n ; i++ ) {
		cin >> a[i];
	}
	
	dfs ( ' ' + a[n] , 1 );
	
	cout << len << endl;
	
	return 0;
}

inline int check ( string a , string b ) {
	
	int lena = a.size() , lenb = b.size();
	int len = min ( lena , lenb );
	
	for ( int i = 1 ; i < len ; i++ ) {
		int flag = 1;
		for ( int j = 0 ; j < i ; j++ ) {
			if ( a[lena - i + j] != b[j] ) {
				flag = 0;
			}
		}
		
		if ( flag ) {
			return i;
		}
	}
	
	return 0;
}

inline void dfs ( string s , int size ) {
	len = max ( len , size );
	for ( int i = 0 ; i < n ; i++ ) {
		if ( vis[i] >= 2 ) {
			continue;
		}
		
		int c = check ( s , a[i] );
		if ( c > 0 ) {
			vis[i]++;
			dfs ( a[i] , size + a[i].size() - c );
			vis[i]--;
		}
	}
}
