#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	
	return true;
}

int main(){
	
	int n;
	cin>>n;
	
	for(int i=2;i*i<=n;i++){
		if(n%i==0&&isprime(i)){
			cout<<n/i<<endl;
			break;
		}
	}
	
	return 0;
}
