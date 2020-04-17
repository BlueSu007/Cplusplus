#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n, cnt = 0;
	string s;
	
	cin >> n >> s;
	
	int len = s.size();
	cnt = len;
	
	for(int i = 0; i < len; i++){
		if(i != 0 && s[i] != '0')
			cout << '+';
			
		cnt--;
		if(s[i] == '0')
			continue;
			
		cout << s[i] << '*' << n << '^' << cnt;
	}
	
	cout << endl;
	
	return 0;
}
