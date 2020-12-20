#include <iostream>
using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	if(d>=b){
	    
        cout<<c-a<<" ";
		cout<<d-b;
		
	}else{
	    
        cout<<c-a-1<<" ";
		cout<<d-b+60;
		
	}
	
	return 0;
	
}

//3 51 8 59
//5 8
