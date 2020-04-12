#include <iostream>
using namespace std;

int main(){
	int sum=0,i=1,j=1;
	char a[20];
	
	while(j<13){
		cin>>a[i];
		
		if(a[i]!='-'){
			sum+=(a[i]-48)*i;
			i++;
		}
		
		j++;
	}
	
	char b,d;
	cin>>b;
	
	int c;
	if(b=='X'){
		c=b-78;
	}else{
		c=b-48;
	}
	
	if(sum%11==c){
		cout<<"Right"<<endl;
	}else{
		for(int k=1;k<j-3;k++){
			if(k==2||k==5){
				cout<<'-';
			}
			cout<<a[k];
		}
		
		if(sum%11==10){
			cout<<"-"<<"X"<<endl;
		}else{
			cout<<"-"<<sum%11<<endl;
		}
	}
	
	return 0;
} 
