#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

unsigned long long tmp[30][30];
unsigned long long map[30][30];

int main(){
	
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	n+=2,m+=2,a+=2,b+=2;
	
	tmp[a][b]=tmp[a-2][b-1]=tmp[a-2][b+1]=tmp[a-1][b-2]
	=tmp[a-1][b+2]=tmp[a+1][b-2]=tmp[a+1][b+2]
	=tmp[a+2][b-1]=tmp[a+2][b+1]=1;
	
	map[2][2]=1;
	
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(tmp[i][j]!=1)
				map[i][j]=max(map[i][j],map[i-1][j]+map[i][j-1]);
		}
	}
	
	cout<<map[n][m]<<endl;
	
	return 0;
}  
