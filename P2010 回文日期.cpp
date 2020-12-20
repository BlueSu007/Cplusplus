#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	
	int n,m,cnt=0;
	cin>>n>>m;
	
	if(92200229>=n&&92200229<=m)		cnt=1;
	
	for(int i=1;i<=12;i++){
		for(int j=1;j<=a[i];j++){
			int year=j%10*1000+j/10*100+i%10*10+i/10;
			int sum=year*10000+i*100+j;
			if(sum>=n&&sum<=m){
				cnt++;
//				cout<<sum<<endl;
			}
		}
	}
	
	cout<<cnt<<endl;
	
	return 0;
} 
