#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n, a, cnt;

int main(){
	
	while(cin >> a)
		cnt += a, n++;
	
	for(int i = 0; i < n - 1; i++)
		cnt *= 2;
		
	cout << cnt << endl;
	
	return 0;
}
