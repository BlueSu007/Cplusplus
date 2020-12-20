#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int visit[10],storage[10],n;

void dfs(int step){
	if(step==n+1){
		for(int i=1;i<=n;i++){
			printf("%5d",storage[i]);
		}
		cout<<endl; 
		return ;
	}
	
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			visit[i]=1;
			storage[step]=i;
			
			dfs(step+1);
			visit[i]=0;
		}
	}
}

int main(){
	
	cin>>n;
	dfs(1);
	
	return 0;
}
