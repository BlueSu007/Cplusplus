#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define mian main
using namespace std;

long long n, a[200000 + 5];
long long x, url, cnt;

int main(){
	
//	freopen("tmp.html", "w", stdout);
	cin >> n;
	
	while(n--){
		cin >> url;
		
		switch(url){
			case 0:
				cin >> x;
				cnt++, a[cnt] = max(a[cnt - 1], x);
				break;
			case 1:
				if(cnt > 0)
					cnt--;
				break;
			case 2:
				cout << a[cnt] << endl;
				break;
		}
	}
	
	return 0;
}
