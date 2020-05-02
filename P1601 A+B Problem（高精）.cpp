#include <bits/stdc++.h>
using namespace std;

int a1[1000],b1[1000],c[1002];

int main(){
	
	string a,b;
	cin>>a>>b;
	
	if(a=="0"||b=="0"){
		cout<<0<<endl;
		exit(0);
	}
	
	int la,lb;
	la=a.size();
	lb=b.size();
	
	for(int i=0;i<=la-1;i++){
		a1[i]=a[la-1-i]-48;
	}
	for(int i=0;i<=lb-1;i++){
		b1[i]=b[lb-1-i]-48;
	}
	
	for(int i=0;i<=999;i++){
		c[i]=a1[i]+b1[i];
	}
	for(int i=0;i<=999;i++){
		if(c[i]>=10){
			c[i+1]++;
			c[i]=c[i]-10;
		}
	}
	
	int i=1001;
	while(c[i]==0){
		i--;
	}
	
	for(;i>=0;i--){
		cout<<c[i];
	}
	
	return 0;
}
