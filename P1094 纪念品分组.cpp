#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int m, n, sum, cnt;
int a[30000 + 5];

int main(){
	
	cin >> m >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a + 1, a + 1 + n);
		
	int left = 1, right = n;
	while(left <= right){
		if(a[left] + a[right] <= m)
			left++;
			
		right--, cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}
