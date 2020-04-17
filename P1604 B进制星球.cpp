#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int a1[2020] , b1[2020], c[2020], n;
char a[2020], b[2020];

int main(){
	
	cin >> n >> a >> b;
	
	int la, lb;
	la = strlen(a);
	lb = strlen(b);
	
	for(int i = 0; i < la; i++)
		if(a[i] >= 'A' && a[i] <= 'Z')
			a1[la - i - 1] = a[i] - 'A' + 10;
		else
			a1[la - i - 1] = a[i] - '0';
			
	for(int i = 0; i < lb; i++)
		if(b[i] >= 'A' && b[i] <= 'Z')
			b1[lb - i - 1] = b[i] - 'A' + 10;
		else
			b1[lb - i - 1] = b[i] - '0';
	
	for(int i = 0; i <= 2019; i++)
		c[i] = a1[i] + b1[i];
	
	for(int i = 0; i <= 2019; i++)
		if(c[i] >= n){
			c[i + 1]++;
			c[i] %= n;
		}
	
	int i = 2019;
	while(c[i] == 0)
		i--;
	
	for(; i >= 0; i--){
		if(c[i] > 9)
			printf("%c", c[i] + 'A' - 10);
		else
			cout << c[i];
	}
	
	return 0;
}
/*
16
1024A
4201B
*/
