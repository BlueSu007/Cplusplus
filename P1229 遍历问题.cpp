#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

string s1, s2;
int ans;

int main(){
	
	cin >> s1 >> s2;
	
	int len1 = s1.size();
	int len2 = s2.size();
	
	for(int i = 0; i < len1; i++){
		for(int j = 1; j < len2; j++){
			if(s1[i] == s2[j] && s1[i + 1] == s2[j - 1])
				ans++;
		}
	}
	
	cout << pow(2, ans) << endl;
	
	return 0;
}
