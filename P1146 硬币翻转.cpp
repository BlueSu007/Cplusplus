#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool a[110];

int main(){
	
	int n,k=1;
	cin>>n;
	
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==k){
				cout<<a[j];
				continue;
			}
			a[j]=!a[j];
			cout<<a[j];
		}
		cout<<endl;
		k++;
	}
	
	return 0;
}
