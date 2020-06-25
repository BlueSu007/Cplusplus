#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int c[100 + 5][2], n;
char a[100 + 5][100 + 5];
char str[] = "yizhong";
int vis[100 + 5][100 + 5];
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1 ,1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
inline bool check ( int x, int y );
inline void dfs ( int x, int y, int k, int cur );

int main() {
	
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < n ; j++ ) {
			cin >> a[i][j];
		} 
	}
	
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < n ; j++ ) {
			if ( a[i][j] == 'y' ) {
				for ( int k = 0 ; k < 8 ; k++ ) {
					int fx = i + dx[k];
					int fy = j + dy[k];
					
					if ( a[fx][fy] == 'i' ) {
						dfs ( i, j, k, 0 ); 
					}
				}
			}
		}
	}
	
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < n ; j++ ) {
			if ( vis[i][j] ) {
				cout << a[i][j];
			}
			else {
				cout << "*";
			}
		}
		
		cout << endl;
	} 
	
	return 0;
}

inline void dfs ( int x, int y, int k, int cur ) {
	if ( cur == 7 ) {
		for ( int i = 0 ; i < 7 ; i++ ) {
			vis[c[i][0]][c[i][1]] = 1;
//			cout << c[i][0] << " " << c[i][1] << endl;
		}
		
		return ;
	}
	
	int fx = x + dx[k];
	int fy = y + dy[k];
	
	if ( cur == 6 || a[fx][fy] == str[cur + 1] ) {
		c[cur][0] = x;
		c[cur][1] = y; 
//		cout << "2333" << endl;
		dfs ( fx, fy, k, cur + 1 );
	}
}
