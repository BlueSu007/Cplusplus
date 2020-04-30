#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, c, m;
int a[100000 + 5];
bool check(int k);

int main(){
	
	cin >> n >> c;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a + 1, a + 1 + n);
	
	int left = 1, right = a[n] - a[1];
	m = n - c;
	
	while(left + 1 < right){
		int mid = (left + right) / 2;
		if(check(mid))
			left = mid;
		else 
			right = mid;
	}
	
	if(check(left))
		cout << left << endl;
	else
		cout << right << endl;
	
	return 0;
}

bool check(int k){
	int cnt = 0;
	int x = a[1];
	
	for(int i = 2; i <= n; i++){
		if(a[i] - x < k)
			cnt++;
		else
			x = a[i];
			
		if(cnt > m)
			return false;
	}
	
	return true;
}
