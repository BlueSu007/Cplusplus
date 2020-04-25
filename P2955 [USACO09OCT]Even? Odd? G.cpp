#include <iostream>
using namespace std;

int main(){
	
	string a;
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a;
		int len=a.size();
		if(a[len-1]%2==0){
			cout<<"even"<<endl;
		}else{
			cout<<"odd"<<endl;
		}
	}
	
	return 0;
}
