#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int weeksum[10] , year = 1900 , month = 1 , day;
long long sum;

bool isrun(int n){
	if(n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
		return true;
	
	return false;
}

int main(){
	
	int n;
	cin >> n;
	
	while ( year < 1900 + n ) {
		
		if ( isrun ( year ) ) {
			a[2] = 29;
		}
		
		day++ , sum++;
		if ( day == a[month] + 1 ) {
			month++;
			day = 1;
		}
		
		if ( month == 13 ) {
			year++;
			month = 1;
		}
		
		if ( day == 13 ) {
			weeksum[sum % 7 + 1 ]++;
		}
		
		a[2] = 28;
	}
	
	cout << weeksum[7];
	
	for(int i = 1; i <= 6; i++)
		cout << " " << weeksum[i];
	
	cout << endl;
	
	return 0;
}
