#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[200000 + 5];
int n;

int main(){
	
	cin >> n;
	int tmp = 1;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i + 1])
			tmp++;
		else{
			cout << a[i] << " " << tmp << endl;
			tmp = 1;
		}
	} 
	
	return 0;
}
