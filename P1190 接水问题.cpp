#include <iostream>
using namespace std;

int a[11000];

int main(){
	
	int n,m,mix=0x7fffffff,max=-1,q;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(i<=m&&a[i]<mix){
			q=i;
			mix=a[i];
		}
		
	}
	
	
	for(int i=m+1;i<=n;i++){
		mix=0x7fffffff;
		
		a[q]+=a[i];

		for(int i=1;i<=m;i++){
			if(a[i]<mix){
				q=i;
				mix=a[i];
			}
			
			//cout<<a[i]<<" ";
		}
		
		//cout<<endl;
	}

	
	for(int i=1;i<=m;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	
	cout<<max;
	
	return 0;
}
