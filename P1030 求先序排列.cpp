#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

void tree(string now, string after){
	if(now.size() > 0){
		char ch = after[after.size() - 1];
		cout << ch;
		
		int k = now.find(ch);
		tree(now.substr(0, k), after.substr(0, k));
		tree(now.substr(k + 1), after.substr(k, now.size() - k - 1));
	}
} 

int main(){
	
	string now, after;
	cin >> now >> after;
	tree(now, after);
	cout << endl;
	
	return 0;
}
