#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

string s[7] = {"", "1/6", "1/3", "1/2", "2/3", "5/6", "1/1"};

int main(){
	
	int n, m;
	cin >> n >> m;
	n = max(n, m);
	
	int k = 6 - n + 1;
	cout << s[k] << endl;
	
	return 0;
}
