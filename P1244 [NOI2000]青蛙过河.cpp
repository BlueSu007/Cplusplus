#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int h, k;
	cin >> h >> k;
	cout << (k + 1) * (1 << h) << endl;
	
	return 0;
} 
