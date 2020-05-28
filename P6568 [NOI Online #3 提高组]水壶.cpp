#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n, k, a[1000000 + 5];
long long asum[1000000 + 5];
long long maxn = LLONG_MIN;
inline int read_();

int main(){
	
	n = read_();
	k = read_();
	
	for(int i = 1; i <= n; i++){
		a[i] = read_();
		asum[i] = asum[i - 1] + a[i];
	}
	
	for(int i = 1; i <= n - k; i++){
		maxn = max(maxn, asum[i + k] - asum[i - 1]);
	}
	
	cout << maxn << endl;
	
	return 0;
}

inline int read_(){
	
	int f = 1, x = 0;
	char ch = getchar();
	
	while(!isdigit(ch)){
		if(ch == '-')
			f = -1;
		
		ch = getchar();
	}
	
	while(isdigit(ch)){
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	
	return f * x;
}
