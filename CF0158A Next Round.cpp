#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1000 + 5];
int tmp, ans, n, score, cnt;

int main(){
	
	cin >> n >> score;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	for(int i = 1; i <= score; i++)
		if(a[i])
			ans++;
		else{
			cout << ans << endl;
			exit(0);
		}
	
	while(a[score] == a[score + 1] && a[score] != 0)
		score++, ans++;
	
	cout << ans << endl;
	
	return 0;
}
