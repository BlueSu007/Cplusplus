#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a[1000 + 5], b[1000 + 5];

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
		
		if(a[i] >= 0)
			b[i] = 1; 
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(b[j] > 0 && a[i] - a[j] >= 0)
				b[i] = max(b[i], b[j] + 1);
		}
	}
	
	if(b[n] == 0)
		cout << "Impossible" << endl;
	else
		cout << b[n] << endl;
	
	return 0;
}
