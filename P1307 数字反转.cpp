#include <iostream>
#include <cstring>
using namespace std;

int main(){

	char a[21]={'0'};
	cin>>a;

	int c=strlen(a),d;

	if(a[0]=='-'){
		cout<<'-';

		for(int i=c-1;i>0;i--){
			if(a[i]!='0'){
				d=i;
				break;
			}
		}

		for(int i=d;i>0;i--){
			cout<<a[i];
		}

	}else{

		/*for(int i=c-1;i>=0;i--){
			if(a[i+1]!='0'){
				cout<<a[i];
			}
		}*/

		for(int i=c-1;i>0;i--){
			if(a[i]!='0'){
				d=i;
				break;
			}
		}

		for(int i=d;i>=0;i--){
			cout<<a[i];
		}
	}

	return 0;
}
