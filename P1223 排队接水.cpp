#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define mian main
using namespace std;

struct person{
	int wait;
	int time;
	int id;
}a[1000100];

void fen(int left, int right);
void bing(int left, int mid, int right);

int main(){
	
//	freopen("P1223_3.in.txt", "r", stdin);
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i].time;
		a[i].id = i;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[i].time > a[j].time){
				swap(a[i], a[j]);
			}else if(a[i].time == a[j].time){
				if(a[i].id > a[j].id){
					swap(a[i], a[j]);
				}
			}
		}
	}
	
	long long sum = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			a[j].wait += a[i].time;
		}
		sum += a[i].wait;
	}
	
	for(int i = 1; i <= n; i++){
		cout << a[i].id << " ";
	}
	
	cout << endl;
	
	printf("%.2lf", (double)sum / n + 0.0000001);
	
	return 0;
}
