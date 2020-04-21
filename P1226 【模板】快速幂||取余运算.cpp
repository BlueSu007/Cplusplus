#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){

	long long a, b, x, ans =1;
	cin >> a >> b >> x;

	cout << a << "^" << b << " mod " << x << "=";

	while(b > 0){
		if(b % 2 == 1){
			ans = ans * a % x;
		}
		a = a * a % x;
		b = b / 2;
	}

	cout << ans % x << endl;

	return 0;
}
