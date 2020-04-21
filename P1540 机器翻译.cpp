#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	
	int n, m, t, ans = 0;
	cin >> m >> n;
	
	vector <int> v;
	
	while(cin >> t){
		if(find(v.begin(), v.end(), t) == v.end()){
			v.push_back(t);
			ans++;
		}
		
		if(v.size() > m)
			v.erase(v.begin());
	}
	
	cout << ans << endl;
	
	return 0;
}
