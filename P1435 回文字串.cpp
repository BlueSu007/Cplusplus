#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int dp1[5000 + 5];
int dp2[5000 + 5];
char str1[5000 + 5], str2[5000 + 5];

int main(){
	
	scanf("%s", str1 + 1);
	
//	abcdedc??
//	??cdedcba
	int len = strlen(str1 + 1);
	for(int i = 1; i <= len; i++){
		str2[i] = str1[len - i + 1];
	}
	
	for(int i = 1; i <= len; i++){
		for(int j = 1; j <= len; j++)
			if(str1[i] == str2[j])
				dp1[j] = dp2[j - 1] + 1;
			else
				dp1[j] = max(dp1[j - 1], dp2[j]);
		
		memcpy(dp2, dp1, sizeof(dp1));
	}
	
	cout << len - dp1[len] << endl;
	
	return 0;
}
