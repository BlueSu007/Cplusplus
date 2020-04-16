#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int n,sum=0,collect=0;
	
	for(int i=1;i<=12;i++){
		sum+=300;
		cin>>n;
		if(sum<n){
			cout<<"-"<<i<<endl;
			return 0;
		}else{
			sum-=n;
			collect+=sum/100;
			sum%=100;
		}
	}
	
	cout<<sum+(collect*100)*1.2<<endl;
	
	return 0;
}
