#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int a[26] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };
int cnt, len;

int main() {
	
	char c, s[100000];
	gets(s);
	
	int len = strlen(s), i = 0;
	
	while ( i < len ) {
		c = s[i];
		if ( c == ' ' ) {
			cnt++;
			i++;
			continue;
		}
		else if ( c >= 'a' && c <= 'z' ) {
			cnt += a[c - 97];
		}
		
		i++;
	}
	
	cout << cnt << endl;
	
	return 0;
}
