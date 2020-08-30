#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main(){
	
	string a;
	int boy=0,girl=0;
	cin>>a;
	
	int len=a.length();
	for(int i=0;i<=len;i++){
		if(a[i]=='b'||a[i+1]=='o'||a[i+2]=='y')
			boy++;
		if(a[i]=='g'||a[i+1]=='i'||a[i+2]=='r'||a[i+3]=='l')
			girl++;
	}
	
	cout<<boy<<endl<<girl<<endl;
	
	return 0;
} 
