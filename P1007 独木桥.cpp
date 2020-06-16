#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[5000 + 5]; 
int len, n;

int main() {
	cin >> len >> n;
	
	int tmp;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> tmp;
		a[tmp] = 1;
	}
	
	int maxn = 0;
	int minn = 0;
	
	for ( int i = 1 ; i <= len ; i++ ) {
		if ( a[i] == 1 ) {
			
			int tmp1, tmp2;
			tmp1 = max( i - 0, len - i + 1 );
			tmp2 = min( i - 0, len - i + 1 );
			
			maxn = max( tmp1, maxn );
			minn = max( tmp2, minn );
		}
	}
	
	cout << minn << " " << maxn << endl;
	
	return 0;
}
