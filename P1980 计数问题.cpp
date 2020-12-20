#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long n,x,cnt=0,b,c,t=0;
	cin>>n>>x;
	
	for(int i=1;i<=n;i++){
		b=i;
        while(b!=0)
        {
            c=b%10;
            b=b/10;
            if(c==x){
				t++;
			}
        }
	}
	
	cout<<t<<endl;
	
	return 0;
}
