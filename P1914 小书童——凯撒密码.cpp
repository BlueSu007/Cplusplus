
/*
	Name: P1914
	Copyright: 2020 BlueSu. All rights reserved. 
	Author: BlueSu
	Date: 05-04-20 13:26
	Description: TiDan [RM5] T-02
*/


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n;
	string a;
	cin >> n >> a;
	
	int len = a.size();
	for(int i = 0; i < len; i++){
		a[i] = (a[i] - 'a' + n) % 26 + 'a';
	}
	
	cout << a;
	
	return 0;
}
