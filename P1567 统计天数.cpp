#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, tmp, ans, step, before;

int main() {
	
	cin >> n >> before;
	
	while ( n-- >= 2 ) {
		
		cin >> tmp;
		if ( tmp >= before ) {
			step++;
		}
		else {
//			cout << endl << endl << "--------------------------------" << endl << endl;
			ans = max( ans, step );
//			cout << ans << endl << "--------------------------------";
			step = 1;
		}
		
		before = tmp;
	}
	
	ans = max( ans, step );
	cout << ans << endl;
	
	return 0;
} 
