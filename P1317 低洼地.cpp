#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	
	int n;
	int start,temp;
	int cnt=0;
	bool flag=true;
	
	cin>>n;
	cin>>start;
	
	for(int i=2;i<=n;i++){
		
		cin>>temp;
		
		if(temp<start&&flag==true){
			flag=false;
			cnt++;
		}
		
		if(temp>start)	flag=true;
		
		start=temp;
	}
	
	cout<<cnt-1<<endl;
	
	return 0;
} 
