#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = 3.14159265358979323;
double n;

int main() {
	
	scanf ( "%lf" , &n );
	printf ( "%.6lf\n%.6lf\n" , n * n * pi , n * n * 2 );
	
	return 0;
}
