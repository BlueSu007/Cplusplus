#include <iostream>
#include <cmath>
#include <cstdio>
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
	
	for(int i=4;i<=n;i+=2){
		
		for(int j=2;j<=i/2;j++){
			if(isprime(j)&&isprime(i-j)){
				cout<<i<<"="<<j<<"+"<<i-j<<endl;
				
				break;
			}
		}
		
	}
	
	return 0;
}
