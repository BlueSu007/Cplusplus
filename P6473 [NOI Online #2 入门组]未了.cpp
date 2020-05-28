#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, l, v;
int m, t;
long long a[200000 + 5], b[200000 + 5];

int main(){
	
//	freopen("endless.in", "r", stdin);
//	freopen("endless.out", "w", stdout);
	cin >> n >> l >> v;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	b[0] = l;
	
	for(int i = 1; i <= n; i++){
		b[i] = b[i - 1] + a[n - i + 1];
	}
	
	cin >> m;
	
	while(m--){
		cin >> t;
		long long distance = (long long)t * v;
		
		if(b[n] <= distance){
			cout << -1 << endl;
			continue;
		}
		
		int left = -1, right = n;
		while((right - left) > 1){
			int mid = (left + right) / 2;
			if(b[mid] > distance){
				right = mid;
			}
			else{
				left = mid;
			}
		}
		
		cout << right << endl;
	}
	
	return 0;
}
