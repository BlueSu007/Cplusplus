#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[10000 + 5], n, m, cnt;

bool isrun(int n){
	if((n % 400 == 0) || ((n % 4 == 0) && (n % 100 != 0))){
		return true;
	}
	
	return false;
}

int main(){
	
	cin >> n >> m;
	
	for(int i = n; i <= m; i++){
		if(isrun(i)){
			cnt++;
			a[cnt] = i;
		}
	}
	
	cout << cnt << endl;
	
	for(int i = 1; i <= cnt; i++){
		cout << a[i] << " ";
	}
	
	return 0;
}
