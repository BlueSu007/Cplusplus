#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

string a, b;
int ans = -1;

int main(){
	
	cin >> a >> b;
	
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a.size() - i + 1; j++){
			if(b.find(a.substr(i, j)) != -1)
				ans = max(j, ans);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
