#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int qwq[30] = { 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 3 , 3 , 3 , 6 , 6 , 10 , 10 , 15 , 21 , 21 , 28 , 28 , 35 , 30 , 30 , 27 , 12 } ;
int n ;

int main () {
	
	scanf ( "%d" , &n ) ;
	printf ( "%d" , qwq[n] ) ;
	
	return 0 ;
}
