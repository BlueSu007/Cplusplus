#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const char dtoc[20]="0123456789ABCDEF";
int main()
{
	int n,m;
	char s[100];
	
	cin>>n;
	cin>>s;
	
	int sum=0;
	int len=strlen(s);
	//s[0] s[1] ... s[len-1]
	int t=1;
	
	for(int i=len-1;i>=0;i--){
		int tmp;
		if(s[i]<='9'&&s[i]>='0')	tmp=s[i]-48;
		else	tmp=s[i]-65+10;
		
		sum+=tmp*t;
		t*=n;
	}

	cin>>m;	
	
	int fsum=sum;
	
	int a[100],p=0;
	do{
		a[p++]=sum%m;
		sum/=m;
	}while(sum!=0);
	
	for(int i=p-1;i>=0;i--){
		if(a[i]>=10){
			printf("%c",a[i]+65-10);
			continue;
		}
		cout<<a[i];
	}
	
 	return 0;
}
