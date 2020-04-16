#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;

struct xuesheng{
	string name;
	int math;
	int chinese;
	int english;
	int id;
	int sum;
}a[1000 + 5];

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i].name >> a[i].chinese >> a[i].math >> a[i].english;
		a[i].sum = a[i].chinese + a[i].math + a[i].english;
		a[i].id = i;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(abs(a[i].chinese - a[j].chinese) <= 5 && abs(a[i].math - a[j].math) <= 5 
			&& abs(a[i].english - a[j].english) <= 5 && abs(a[i].sum - a[j].sum) <= 10){
				cout << a[i].name << " " << a[j].name << endl;
			}
		}
	}
	
	return 0;
}
