#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int flag = 0, x, y, z, k;
	cin >> x >> y >> z;
	k = __gcd(__gcd(x, y), z);
	x /= k;
	y /= k;
	z /= k;
	
	for(int j = 123; j <= 987; j++){
		
		int q = j * y / x;
		int r = j * z / x;
		
		int a = j / 100 % 10, b = j / 10 % 10, c = j % 10;
		int d = q / 100 % 10, e = q / 10 % 10, f = q % 10;
		int g = r / 100 % 10, h = r / 10 % 10, i = r % 10;
		
		if(b != a && c != a && c != b && d != a && d != b && d != c
		 && e != a && e != b && e != c && e != d && f != a && f != b && f != c && f != d && f != e
		 && g != a && g != b && g != c && g != d && g != e && g != f
		 && h != a && h != b && h != c && h != d && h != e && h != f && h != g
		 && i != a && i != b && i != c && i != d && i != e && i != f && i != g && i != h) 
		 {
	//		
	//		if(w * y == q && w * z == r){
	//			cout << w << " " << q << " " << r << endl;
	//			flag = 1;
	//		} 
	
			if(((j / 100) * (j / 10 % 10) * (j % 10) * (q / 100) * (q / 10 % 10) * (q % 10)
			 * (r / 100) * (r / 10 % 10) * (r % 10)) == (1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9)){
				cout << j << " " << q << " " << r << endl;
				flag = 1;
			}
		}
	}
	
	if(!flag)
		cout << "No!!!" << endl;
	
	return 0;
}
