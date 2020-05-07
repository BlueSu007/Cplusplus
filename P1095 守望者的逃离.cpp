#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[300000 + 5];

int main(){
	
	int m, s, t;
	int anst = 0, anss = 0;
	cin >> m >> s >> t;
	
	for(int i = 1; i <= t; i++){
		if(m >= 10)
			a[i] = a[i - 1] + 60, m -= 10;
		else
			a[i] = a[i - 1], m += 4;
	}
	
	for(int i = 1; i <= t; i++){
		a[i] = max(a[i], a[i - 1] + 17);
		
		if(a[i] >= s)
			cout << "Yes\n" << i << endl, exit(0);
	}
	
	cout << "No\n" << a[t] << endl;
	
	return 0;
}
