#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct person{
	string name;
	string sos;
	int times;
}a[100 + 5];

int n, maxn = -1;
int find_(string s);

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i].name >> a[i].sos;
		a[i].times = find_(a[i].sos);
	}
	
	for(int i = 1; i <= n; i++){
		maxn = max(maxn, a[i].times);
	}
	
	for(int i = 1; i <= n; i++){
		if(a[i].times == maxn){
			cout << a[i].name << " ";
		}
	}
	
	cout << endl << maxn << endl;
	
	return 0;
}

int find_(string s){
	int ans = 0;
	string tmp;
	int len = s.size();
	
	for(int i = 0; i < len; i++){
		int j = i + 2;
		for(int k = i; k <= j; k++){
			tmp += s[k];
		}
		
		if(tmp == "sos")
			ans++;
		
		tmp = "";
	}
	
	return ans;
}
