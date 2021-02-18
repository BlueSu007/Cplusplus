#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
using namespace std ;

int k ;
string s ;
map < char , int > pam1 ;
map < int , char > pam2 ;
inline void init () ;
inline void qwq () ;
inline void qaq () ;

int main () {

	scanf ( "%d" , &k ) ;
	init () ;
	while ( k-- ) {
		cin >> s ;
		if ( isdigit ( s[1] ) && s[0] == 'R' && s.find ( 'C' ) != string::npos ) {
			qwq () ;
		}
		else {
			qaq () ;
		}
	}

	return 0 ;
}

inline void init () {
	pam1['A'] = 1 , pam1['B'] = 2 , pam1['C'] = 3 , pam1['D'] = 4 , pam1['E'] = 5 ;
	pam1['F'] = 6 , pam1['G'] = 7 , pam1['H'] = 8 , pam1['I'] = 9 , pam1['J'] = 10 ;
	pam1['K'] = 11 , pam1['L'] = 12 , pam1['M'] = 13 , pam1['N'] = 14 , pam1['O'] = 15 ;
	pam1['P'] = 16 , pam1['Q'] = 17 , pam1['R'] = 18 , pam1['S'] = 19 , pam1['T'] = 20 ;
	pam1['U'] = 21 , pam1['V'] = 22 , pam1['W'] = 23 , pam1['X'] = 24 , pam1['Y'] = 25 ;
	pam1['Z'] = 26 ;

	pam2[1] = 'A' , pam2[2] = 'B' , pam2[3] = 'C' , pam2[4] = 'D' , pam2[5] = 'E' ;
	pam2[6] = 'F' , pam2[7] = 'G' , pam2[8] = 'H' , pam2[9] = 'I' , pam2[10] = 'J' ;
	pam2[11] = 'K' , pam2[12] = 'L' , pam2[13] = 'M' , pam2[14] = 'N' , pam2[15] = 'O' ;
	pam2[16] = 'P' , pam2[17] = 'Q' , pam2[18] = 'R' , pam2[19] = 'S' , pam2[20] = 'T' ;
	pam2[21] = 'U' , pam2[22] = 'V' , pam2[23] = 'W' , pam2[24] = 'X' , pam2[25] = 'Y' ;
	pam2[26] = 'Z' ;
}

inline void qwq () {
	int rNum = 0 , cNum = 0 , len = s.size () , i = 0 ;
	while ( s[++i] != 'C' ) {
		rNum = rNum * 10 + ( s[i] - '0' ) ;
	}

	while ( ++i < len ) {
		cNum = cNum * 10 + ( s[i] - '0' ) ;
	}

//	 cout << cNum << " " ;

	int array2[10] = { 0 } , cnt2 = 0 ;
	while ( cNum ) {
		array2[++cnt2] = cNum % 26 ;
		cNum = cNum / 26 - ! ( cNum % 26 ) ;
		if ( ! array2[cnt2] ) {
			array2[cnt2] = 26 ;
		}
	}

	for ( int i = cnt2 ; i >= 1 ; i-- ) {
		printf ( "%c" , pam2[array2[i]] ) ;
	}
	cout << rNum << endl ;
}

inline void qaq () {
	int cNum = 0 , rNum = 0 , len = s.size () , i = 0 ;
	while ( ! isdigit ( s[i] ) ) {
		cNum = cNum * 26 + pam1[s[i++]] ;
	}

	while ( i < len ) {
		rNum = rNum * 10 + ( s[i++] - '0' ) ;
	}

	printf ( "R%dC%d\n" , rNum , cNum ) ;
}

/*
4
R23C55
BC23
R228C494
R98C688

BC23
R23C55
RZ228
ZL98
*/
