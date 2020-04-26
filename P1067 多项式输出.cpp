#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int a[100 + 5];

int main(){
	
	cin >> n;
	
	for(int i = n; i >= 0; i--){
		cin >> a[i];
	}
	
	for(int i = n; i >= 0; i--){
		if(a[i]){
			if(i != n && a[i] > 0)
				cout << '+';
			if(abs(a[i]) > 1 || i == 0)
				cout << a[i];
			if(a[i] == -1 && i)
				cout << '-';
			if(i > 1)
				cout << "x^" << i;
			if(i == 1)
				cout << "x";
		}
	}
	
	return 0;
}
