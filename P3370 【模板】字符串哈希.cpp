#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

string tmp;
int n;
set <string> tes;

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> tmp;
		tes.insert(tmp);
	}
	
	cout << tes.size() << endl;
	
	return 0;
}
