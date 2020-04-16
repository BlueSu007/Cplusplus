#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;

struct xuesheng{
	string name;
	int age;
	int prize;
}a[1000100];

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i].name >> a[i].age >> a[i].prize;
		a[i].age++;
		a[i].prize *= 1.2;
		
		if(a[i].prize > 600)
			a[i].prize = 600;
		
		cout << a[i].name << " " << a[i].age << " " << a[i].prize << endl;
	}
	
	return 0;
}
