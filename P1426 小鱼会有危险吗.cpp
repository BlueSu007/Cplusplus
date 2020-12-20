#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int s,x;
	cin>>s>>x;
	
	x*=2;
	
	double distance=7,cnt=0;
	
	while(true){
		cnt+=distance;
		distance*=0.98;
		
		if(cnt>=s){
			if(distance*0.98<=x){
				cout<<"y"<<endl;
				break;
			}else if(distance*0.98>x){
				cout<<"n"<<endl;
				break;
			}
		}
	}
	
	return 0;
}
