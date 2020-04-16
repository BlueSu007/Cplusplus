#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int a[26];

bool isprime(int n){
	
	if(n==1){
		return 0;
	}
	
	for(int i=2;i*i<n;i++){
		if(n%i==0){
			return 0;
		}
	}
	
	return 1;
}

int main(){
	
	int maxn=0,minn=0x7fffff;
	
	char s[100];
	cin>>s;
	
	int len=strlen(s);
	
	for(int i=0;i<len;i++){
		a[(int)s[i]-97]++;
	}
	
	for(int i=0;i<26;i++){
		maxn=max(maxn,a[i]);
		if(a[i]!=0&&a[i]<minn){
			minn=a[i];
		}
	}
	
	//cout<<maxn<<" "<<minn<<endl;
	
	if(maxn-minn>0&&isprime(maxn-minn)){
		cout<<"Lucky Word"<<endl<<maxn-minn;
	}else{
		cout<<"No Answer"<<endl<<0<<endl;
	}

	return 0;
}
