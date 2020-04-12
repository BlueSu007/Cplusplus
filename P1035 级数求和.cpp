#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	int k,i=1;
	cin>>k;
	
	double n=0;
	while(n<=k){
		n+=1.00/i;
		i++;
	}
	
	cout<<i-1<<endl;
	
	return 0;
}
