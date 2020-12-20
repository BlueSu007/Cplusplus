#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long abc;
abc a[0x7ffffff];
abc n,m;
abc wood_lenth(abc lleft,abc lright);

int main(){
	
	cin>>n>>m;
	
	for(abc i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	cout<<wood_lenth(1,a[n])-1<<endl;
	
	return 0;
}

abc wood_lenth(abc lleft,abc lright){
	if(lleft==lright){
		return lleft;
	}
	
	abc lmid=(lleft+lright)>>1;
	abc sum=0;
	
	for(abc i=1;i<=n;i++){
		if(a[i]>lmid)	sum+=a[i]-lmid;
	}
	
	if(sum>=m){
		return wood_lenth(lmid+1,lright);
	}else{
		return wood_lenth(lleft,lmid);
	}
	
}
