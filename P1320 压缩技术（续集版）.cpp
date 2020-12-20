#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

char a, b = '0';
int n, ans[1000100], cnt = 1;

int main(){
	
	while(cin >> a){
		n++;
		if(a == b)
			ans[cnt]++;
		else
			ans[++cnt]++, b = a;
	}
	
	cout << sqrt(n);
	
	for(int i = 1; i <= cnt; i++){
		cout << " " << ans[i];
	}
	
	return 0;
}
