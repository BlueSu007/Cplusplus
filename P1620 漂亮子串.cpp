#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long countO,countX,maxO,maxX;
	
	while(cin>>countO>>countX>>maxO>>maxX){
		
		maxO=min(countO,maxO);
		maxX=min(countX,maxX);
		
		if(maxO == 0)
		{
			cout<<maxX<<endl;
		}
		else if(maxX == 0)
		{
			cout<<maxO<<endl;
		}
		else if((countO+1)*maxX < countX)
		{
			cout<<(countO+1)*maxX+countO<<endl;
		}
		else if((countX+1)*maxO < countO)
		{
			cout<<(countX+1)*maxO+countX<<endl;
		}
		else
		{
			cout<<countO+countX<<endl;
		}
	}
	return 0;
}
