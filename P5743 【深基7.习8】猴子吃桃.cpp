#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long a = 1;
int n;

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n - 1; i++)
		a += 1, a *= 2;
		
	cout << a << endl;
	
	return 0;
}
