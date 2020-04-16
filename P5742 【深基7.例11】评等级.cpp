#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct xuesheng{
	string name;
	int x;
	int y;
	int z;
}a[1000 + 5];

bool ifgood(xuesheng a){
	return a.z > 140 && ((a.x * 0.7) + (a.y * 0.3)) >= 80;
}

int n;

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i].name >> a[i].x >> a[i].y;
		a[i].z = a[i].x + a[i].y;
		
		if(ifgood(a[i]))
			cout << "Excellent" << endl;
		else
			cout << "Not excellent" << endl;
	}
	
	return 0;
} 
