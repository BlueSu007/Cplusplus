#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct person{
	int yyyy;
	int mm;
	int dd;
	string name;
	
	bool operator < (person tmp) const{
		if(yyyy != tmp.yyyy)
			return yyyy < tmp.yyyy;
		if(mm != tmp.mm)
			return mm < tmp.mm;
		if(dd != tmp.dd)
			return dd < tmp.dd;
	}
	
}a[100 + 5];

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i].name >> a[i].yyyy >> a[i].mm >> a[i].dd;
	}
	
	stable_sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= n; i++)
		cout << a[i].name << endl;
	
	return 0;
}
