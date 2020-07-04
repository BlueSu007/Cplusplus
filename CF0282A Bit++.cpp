#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a;
char c;

int main(){
	
	cin >> n;
	
	while(n--){
		cin >> c;
		
		switch(c){
			case 'X':
				cin >> c >> c;
				switch(c){
					case '-':
						a--;
						break;
					case '+':
						a++;
						break;
				}
				break;
			case '-':
				cin >> c >> c;
				a--;
				break;
			case '+':
				cin >> c >> c;
				a++;
				break;
		}
	}
	
	cout << a << endl;
	
	return 0;
}
