#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n; 
int shanshu(char *a,int k){
	n=strlen(a);
	while(k>0){
		for(int i=0;i<n;i++){
			if(i==n-1){
				n--;
				break;
			}
			else if(a[i]>a[i+1]){
				for(int j=i;j<n-1;j++){
					a[j]=a[j+1];
				}
				n--;
				break;
			}
		}
		k--;
	}
	return n;
}

int main(){
	char* input=new char();
	cin>>input;
	int k;
	cin>>k;
	int m=shanshu(input,k);
	int b=0;
	while((b<(m-1))&&(input[b]=='0')){
		b++;
	}
	for(int i=b;i<n;i++){
		cout<<input[i];
	}
	return 0;
}
