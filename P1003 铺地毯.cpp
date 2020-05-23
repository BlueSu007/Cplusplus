#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

//set map's variable
struct map{
	int lenthx, lenthy;
	int sx, sy;
	int ex, ey;
	int id;
}a[10000 + 5];

//RT
int n, x, y;

int main(){
	
	//input
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i].sx >> a[i].sy >> a[i].lenthx >> a[i].lenthy;
		a[i].id = i;
		a[i].ex = a[i].sx + a[i].lenthx;
		a[i].ey = a[i].sy + a[i].lenthy;
	}
		
	cin >> x >> y;
	
	//find: from the highest map to the lowest map
	for(int i = n; i >= 1; i--){
		//if not map limit exceeded >>
		if(a[i].ex >= x && a[i].ey >= y && a[i].sx <= x && a[i].sy <= y){
			//output answer
			cout << a[i].id << endl;
			//end program
			exit(0);
		}
	}
	
	//otherwise: output "not found"(-1)
	cout << -1 << endl;
	
	return 0;
}
