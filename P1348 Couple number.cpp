#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n, m;
	int ans = 0;
	cin >> n >> m;
	
	for(int i = n; i <= m; i++)
		if(i % 4 == 0 || i % 2)
			ans++;
			
	cout << ans << endl;
	
	return 0;
}
