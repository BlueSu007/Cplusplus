#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	
	int n, m,cnt = 1, sum = 1;
	queue <int> q;
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	
	while(!q.empty()){
		if(cnt == m){
			cout << q.front() << " ";
			q.pop();
			cnt = 1;
		}
		
		cnt++;
		q.push(q.front());
		q.pop();
	}
	
	return 0;
}
