#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

map <string, int> pam;
string s[10 + 5], a, b;
int k, n, m, paw;

int main(){
	
	cin >> k;
	
	for(int i = 0; i < k; i++){
		cin >> s[i];
	}
	
	for(int i = 0; i < k; i++){
		cin >> a >> n >> m;
		
		if(m == 0)
			paw = 0;
		else
			paw = n / m;
		pam[a] -= m * paw;
		
		for(int j = 0; j < m; j++){
			cin >> b;
			pam[b] += paw;
		}
	}
	
	for(int i = 0; i < k; i++){
		cout << s[i] << " " << pam[s[i]] << endl;
	}
	
	return 0;
}
