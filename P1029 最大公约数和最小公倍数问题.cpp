#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
	if(b==0){
		return a;
	}
	
	return gcd(b,a%b);
}

int lcm(int a,int b){
	return a*b/gcd(a,b);
}

int main(){
	
	int x,y,ans=0;
	cin>>x>>y;
	
	for(int i=x;i<=y;i++){ 
        int j=x*y/i;
        if(gcd(i,j)==x&&lcm(i,j)==y)    ans++; 
    }
	
	cout<<ans<<endl;
	
	return 0;
}
