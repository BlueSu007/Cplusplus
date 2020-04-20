#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct point{
	double x;
	double y;
	double z;
	
	bool operator < (point tmp) const{
		return z < tmp.z;
	}
}a[50000 + 5];

double cal(point a, point b);

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
		
	stable_sort(a + 1, a + 1 + n);
	
	double cnt = 0;
	for(int i = 1; i < n; i++)
		cnt += cal(a[i], a[i + 1]);
	
	printf("%.3lf", cnt + 0.00001);
	
	return 0;
}

double cal(point a, point b){
	double ans = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2));
}
