#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct cow{
	int start;
	int end;
}a[1000000 + 5];

int n, leftn, rightn, ans1, ans2;
bool cmp(cow x, cow y){
	return x.start < y.start;
}

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i].start >> a[i].end;
	}
	
	sort(a + 1, a + 1 + n, cmp);
	
	leftn = a[1].start;
	rightn = a[1].end;
	
	for(int i = 2; i <= n; i++){
		if(a[i].start <= rightn)
			rightn = max(a[i].end, rightn);
		else{
			ans1 = max(rightn - leftn, ans1);
			ans2 = max(a[i].start - rightn, ans2);
			leftn = a[i].start;
			rightn = a[i].end;
		}
	}
	
	cout << max(rightn - leftn, ans1) << " " << ans2 << endl;
	
	return 0;
}
