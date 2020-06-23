#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

char s[100] = {}, t;
int flag, i;
unsigned long long n;

int main() {
	
	cin >> s;
	
	for ( int j = 0 ; s[j] != '\0' ; j++ ) {
		
		if ( j - i == 19 ) {
			t = 1;
			for ( int k = j ; k >= i ; k-- ) {
				if ( t && s[k] == '0' ) {
					continue;
				}
				else {
					t = 0;
					cout << s[k];
				}
			}
			
			break;
		}
		
		t = s[j + 1];
		
		if ( t == '.' || t == '/' || t == '%' || t == '\0' ) {
			
			while ( flag && s[i] == '0' ) {
				i++;
			}
			
			n = s[j] - '0';
			for ( int k = j - 1 ; k >= i ; k-- ) {
				n *= 10;
				n += s[k] - '0';
			}
			
			cout << n;
			if ( t == '%' ) {
				cout << t << endl;
				exit(0);
			}
			
			if ( t != '\0' ) {
				cout << t;
			}
			
			i = j + 2;//i = ++j++;
			
			if ( t == '.' ) {
				flag = 1;
			}
		}
	}
	
	return 0;
}
