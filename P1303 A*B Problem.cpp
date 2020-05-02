#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm> 
using namespace std;

int a1[100000], b1[100000], c[100000];

int main(){
	
	string a, b;
	cin >> a >> b; 
	
	if(a == "0" || b == "0"){
		cout << 0 << endl;
		exit(0);
	}
	
	int la, lb, i, j;
	la = a.size(); 
	lb = b.size();
	
	for(i = 0; i <= la - 1; i++)
		a1[i] = a[la - 1 - i] - '0';
	for(i = 0; i <= lb - 1; i++)
		b1[i] = b[lb - 1 - i] - '0';
		
	for(i = 0; i <= la - 1; i++)
		for(j = 0; j <= lb - 1; j++)
			c[i + j] = a1[i] * b1[j] + c[i + j];
			
	for(i = 0; i <= 99999; i++)
		if(c[i] >= 10){
			c[i + 1] = c[i + 1] + c[i] / 10;
			c[i] = c[i] % 10;
		}
			
	i = 99999;
	while(c[i] == 0)
		i--;
		
	for(; i >= 0; i--)
		cout << c[i];
	cout << endl;

	return 0;
}
