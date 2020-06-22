#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1000000 + 5], b[1000000 + 5];
int n, len, ans;
string s;
inline bool isreverse();
inline void change();
inline void add();

int main() {
	
	cin >> n >> s;
	len = s.size();
	
	//CHANGE TO DEC.
	for ( int i = len - 1 ; i >= 0 ; i-- ) {
		if ( s[i] >= '0' && s[i] <= '9' ) {
			a[len - i - 1] = s[i] - '0';
		}
		else {
			a[len - i - 1] = s[i] - 'A' + 10;
		}
	}
	
	//REPEAT UNTILL IT'S REVERSE
	while ( !isreverse() ) {
		//REVERSE NUMBER
		change();
		//ADD REVERSE-VER. AND UNREVERSE-VER.
		add();
		//STEP PLUS ONE
		ans++;
		
		//IF IT'S ALREADY 30 STEPS -> BREAK
		if ( ans >= 30 ) {
			break;
		}
	}
	
	//LIKE PROMLEM DESCRIPTION
	if ( ans >= 30 ) {
		cout << "Impossible!" << endl;
	}
	else{
		cout << "STEP=" << ans << endl;
	}
	
	return 0;
}

//SEE IF A[] IS REVERSE
inline bool isreverse() {
	for ( int i = 0 ; i < len / 2 ; i++ ) {
		if ( a[i] != a[len - i - 1] ) {
			return false;
		}
	}
	
	return true;
}

//EQUAL TO STANDARD-TEMPLATE-LIBRARY: REVERSE();
inline void change() {
	for ( int i = len - 1 ; i >= 0 ; i-- ) {
		b[len - i - 1] = a[i];
	}
}

//HIGH-PRECISION ADDITION
inline void add() {
	
	len += 10;
	for ( int i = 0 ; i < len ; i++ ) {
		a[i] += b[i];
		a[i + 1] += a[i] / n;
		a[i] %= n;
	}
	
	while ( !a[len - 1] ) {
		len--;
	}
}
