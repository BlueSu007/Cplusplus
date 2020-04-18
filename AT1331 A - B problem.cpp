#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n, m, x, y, ans = -1000;
	cin >> n >> m;
	x = n, y = m;
	
    ans = max(ans, (x % 100 + 900 - y));
    ans = max(ans, ((x / 100) * 100 + x % 10 + 90) - y);
    ans = max(ans, x + 9 - x % 10 - y);
    ans = max(ans, x - (y % 100 + 100));
    ans = max(ans, x - ((y / 100) * 100 + y % 10));
    ans = max(ans, x - (y - y % 10));
    
    cout << ans << endl;
	
	return 0;
}
