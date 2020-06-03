#include <iostream>
#include <cstdio>
using namespace std;

int w, x, h, ans;
int q, x1, y1, z1;
int x2, y2, z2;
int a[30 + 5][30 + 5][30 + 5];

int main() {
	
	ios::sync_with_stdio( false );
	cin >> w >> x >> h >> q;
	
	for ( int i = 1 ; i <= q ; i++ ) {
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		
		for ( int j = x1 ; j <= x2 ; j++ )
			for ( int k = y1 ; k <= y2 ; k++ )
				for ( int l = z1 ; l <= z2 ; l++ )
					a[j][k][l] = 1;
	}
	
	for ( int i = 1 ; i <= w ; i++ )
		for ( int j = 1 ; j <= x ; j++ )
			for ( int k = 1 ; k <= h ; k++ )
				ans += a[i][j][k];
	
	cout << ( w * x * h ) - ans << endl;
	
	return 0;
}
