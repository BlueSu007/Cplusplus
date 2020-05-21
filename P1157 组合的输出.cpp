#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define mian main
#define flase false
#define ture true
using namespace std;

int n, m;
int vis[20 + 5], a[20 + 5];
void dfs(int step, int last_number);

int main(){
	
	cin >> n >> m;
	dfs(0, 0);
	
	return 0;
}

void dfs(int step, int last_number){
	if(step == m){
		for(int i = 1; i <= m; i++){
			cout << setw(3) << a[i];
		}
		cout << endl;
		return ;
	}
	
	if(step == 0){
		for(int i = 1; i <= n - m + 1; i++){
			if(!vis[i]){
				vis[i] = true;
				a[step + 1] = i;
				dfs(step + 1, i);
				vis[i] = false;
			}
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			if(!vis[i] && i > last_number){
				vis[i] = true;
				a[step + 1] = i;
				dfs(step + 1, i);
				vis[i] = false;
			}
		}
	}
	
}
