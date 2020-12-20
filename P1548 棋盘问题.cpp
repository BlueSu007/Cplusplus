// luogu-judger-enable-o2
#include <iostream>
using namespace std;

int main(){
	int n,m,sqare=0,recon=0,icnt=0,jcnt=0;
	cin>>n>>m;
	
	if(n!=m)
		sqare=n*m+(m-n)*n;
	else{
		for(int i=1;i<=n;i++){
			sqare+=i*i;
		}
	}
		
	
	for(int i=1;i<=n;i++){
		icnt+=i;
	}
	
	for(int i=1;i<=m;i++){
		jcnt+=i;
	}
	
	recon=(icnt*jcnt)-sqare;
	
	cout<<sqare<<" "<<recon;
	
	return 0;
}
