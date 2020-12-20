#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool a[100000];

inline void _put_(bool spfa, int start, int end);

int main(){
	
	int n, tmp, cnt = 0, u = 1;
	bool spfa = false;
	
	cin >> n;
	
	while(!cin.eof()){
		cin >> tmp;
		_put_(spfa, u, u + tmp);
		u += tmp;
		spfa = !spfa;
	}
	
	for(int i = 1; i <= n * n; i++){
		if(cnt % n == 0 && cnt != 0){
			cout << endl;
		}
		
		cnt++;
		cout << a[cnt];
	}
	
	return 0;
}

inline void _put_(bool spfa, int start, int end){
	for(int i = start; i <= end; i++){
		a[i] = spfa;
	}
}
