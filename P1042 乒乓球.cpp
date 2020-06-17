#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int win[1000000], won, lost;

int main() {
	
	ios::sync_with_stdio( false );
	char c;
	
	for ( int i = 1 ; ; i++ ) {
		cin >> c;
		if ( c == 'E' ) {
			win[i] = -1;
			break;
		}
		
		if ( c == 'W' ) {
			win[i] = 0;
		}
		else {
			win[i] = 1;
		}
	}
	
	for ( int i = 1 ; ; i++ ) {
		if ( !win[i] ) {
			won++;
		}
		else if ( win[i] > 0 ) {
			lost++;
		}
		else{
			cout << won << ':' << lost << endl << endl;
			break;
		}
		
		if ( won - lost >= 2 || lost - won >= 2 ) {
			if ( won >= 11 || lost >= 11 ) {
				cout << won << ':' << lost << endl;
				won = 0, lost = 0;
			}
		}
	}
	
	won = lost = 0;
	
	for ( int i = 1 ; ; i++ ) {
		if ( !win[i] ) {
			won++;
		}
		else if ( win[i] > 0 ) {
			lost++;
		}
		else{
			cout << won << ':' << lost << endl << endl;
			break;
		}
		
		if ( won - lost >= 2 || lost - won >= 2 ) {
			if ( won >= 21 || lost >= 21 ) {
				cout << won << ':' << lost << endl;
				won = 0, lost = 0;
			}
		}
	}
	
	return 0;
}
