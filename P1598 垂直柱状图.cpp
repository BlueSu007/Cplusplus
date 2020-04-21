#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[26 + 5];

int main(){
	
	string s;
	int maxn = 0, n = 4;
	
	while(n--){
		getline(cin, s);
		int len = s.size();
		for(int i = 0; i < len; i++){
			if(s[i] >= 'A' && s[i] <= 'Z')
				a[s[i] - 65 + 1]++;
		}
	}
	
	for(int i = 1; i <= 26; i++){
		maxn = max(maxn, a[i]);
	}
	
	for(int i = maxn; i >= 1; i--){
		for(int j = 1; j <= 26; j++){
			if(a[j] >= i)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	
	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
	
	return 0;
}
