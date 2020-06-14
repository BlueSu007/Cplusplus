#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int a, b, c;
	int n;
	cin >> n;
	
//	if(n < 3){
//		cout << -1;
//		exit(0);
//	}
	if(n % 14 == 0){
		cout << n / 14 << " " << n / 14 << " " << n / 14;
		exit(0);
	}
	else if(n == 0){
		cout << "0 0 0";
		exit(0);
	}
	
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt = 0;
	
	for(int i = n / 14; i >= 0; i--)
		for(int j = i; j <= n / 4; j++)
			for(int k = i; k <= n / 3; k++)
				if(i * 7 + j * 4 + k * 3 == n){
					cout << i << " " << j << " " << k;
					exit(0);
				}
					
	cout << -1;
	
	return 0;
} 
