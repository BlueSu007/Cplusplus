#include <bits/stdc++.h>
using namespace std;

int a[2000000 + 5];
int n, m;

int main(){
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + m);
	
	for(int i = 1; i <= m; i++){
		cout << a[i] << " ";
	}
	
	return 0;
}
