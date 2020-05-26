#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a[30000 + 5];
int cow1[30000 + 5];
int cow2[30000 + 5];

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int ans = -1;
	
	for(int i = 1; i <= n; i++){
		for(int j = i - 1; j >= 1; j--){
			if(a[i] <= a[j])
				cow1[i] = max(cow1[i], cow1[j]);
			if(a[i] == a[j])
		 		break;
		}
		
		cow1[i]++;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i - 1; j >= 1; j--){
			if(a[i] >= a[j])
				cow2[i] = max(cow2[i], cow2[j]);
			if(a[i] == a[j])
		 		break;
		}
		
		cow2[i]++;
	}
	
	for(int i = 1; i <= n; i++){
		ans = max(ans, cow1[i]);
		ans = max(ans, cow2[i]);
	}
	
	cout << n - ans << endl;
	
	return 0;
} 
