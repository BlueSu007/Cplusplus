#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n, ans = 0;
	cin >> n;
	
	int a, b, c;
	while(n--){
		cin >> a >> b >> c;
		if(a + b + c >= 2)
			ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
