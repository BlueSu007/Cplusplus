#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

int queue[160000 + 5][2];
int head, tail;
int a[400 + 5][400 + 5];
int n, m, sx, sy, ex, ey;
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(){
	
	cin >> n >> m >> sx >> sy;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = -1;
	
	head = tail = 0;
	queue[tail][0] = sx;
	queue[tail][1] = sy;
	tail++;
	a[sx][sy] = 0;
	
	while(head < tail){
		for(int i = 0; i < 8; i++){
			int fx = queue[head][0] + dx[i];
			int fy = queue[head][1] + dy[i];
			
			if(fx > 0 && fy > 0 && fx <= n && fy <= m && a[fx][fy] == -1){
				queue[tail][0] = fx;
				queue[tail][1] = fy;
				tail++;
				a[fx][fy] = a[queue[head][0]][queue[head][1]] + 1;
			}
		}
		
		head++;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << left << setw(5) << a[i][j];
		}
		
		cout << endl;
	}
	
	return 0;
} 
