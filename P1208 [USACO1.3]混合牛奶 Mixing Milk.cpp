#include <iostream>
#include <algorithm> 
using namespace std;

struct milk{
	int p,num;
};

int cmp(milk x, milk y){
	return x.p<y.p;
}

int main(){ 
	int n,m;
	cin>>n>>m;
	struct milk a[m];
	
	for(int i=0;i<m;i++)
		cin>>a[i].p>>a[i].num;
	
	sort(a,a+m,cmp);
	
	int ans=0;	
	for(int i=0;i<m;i++){
		if(n>=a[i].num){
			ans+=a[i].p*a[i].num;
			n-=a[i].num;
		}else{
			ans+=a[i].p*n;
			break;
		}
	}
	
	cout<<ans<<endl;
		
	return 0;
}
