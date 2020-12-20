#include <iostream>
using namespace std;

int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

int fx,fy,sx,sy;
int visit[1005][1005];
int ans=0,m,n,t,g[1005][1005];
void dfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return ;
	}

	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		
		if(nx>=1&&nx<=m&&ny>=1&&ny<=n
		&&visit[nx][ny]==0&&g[nx][ny]!=1){
			visit[nx][ny]=1;
			dfs(nx,ny);
			visit[nx][ny]=0;
		}
	}
}

int main(){
	cin>>m>>n>>t;
	cin>>sx>>sy>>fx>>fy;
	int x,y;
	for(int i=1;i<=t;i++){
		cin>>x>>y;
		g[x][y]=1;
	}
	
	visit[sx][sy]=1;
	dfs(sx,sy);
	
	cout<<ans<<endl;
	
	return 0;
}
