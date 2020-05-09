#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int apple(int m, int n){
	if(m == 0 || m == 1 | n == 1)
		return 1;
	if(m < n)
		return apple(m, m);
	if(m >= n)
		return apple(m - n, n) + apple(m, n - 1);
}

int main(){
	
	int n, m, s;
	cin >> s;
	
	while(s--){
		cin >> m >> n;
		cout << apple(m, n) << endl;
	}
	
	return 0;
}
