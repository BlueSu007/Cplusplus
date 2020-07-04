#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	long long n, m, a;
	cin >> n >> m >> a;
	cout << ((n - 1) / a + 1) * ((m - 1) / a + 1) << endl;
	
	return 0;
}
