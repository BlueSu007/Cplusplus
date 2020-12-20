#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
using namespace std;

int main(){
	
	int n,a,b;
    cin>>n;
    
    int ans=0x7ffffff,x;
    
    for(int i=1;i<=3;i++){
        cin>>a>>b;
        x=ceil(n*1.0/a)*b;
        ans=min(x,ans);
    }
    
    cout<<ans<<endl;
    
    return 0;
}
