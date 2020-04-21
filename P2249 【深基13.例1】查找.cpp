#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, k;
int a[1000000 + 5];

int erfen(int left, int right, int k);

int main(){
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= m; i++){
		cin >> k;
		cout << erfen(1, n, k) << " ";
	}
	
	return 0;
}

int erfen(int left, int right, int k){
	if(left == right){
		if(a[left] == k)
			return left;
		else
			return -1;
	}
	
	int mid = (left + right) / 2;
	if(k <= a[mid]){
		return erfen(left, mid, k);
	}
	else{
		return erfen(mid + 1, right, k);
	}
}
