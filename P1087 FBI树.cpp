#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string s;

void FBI(int left,int right)
{
	int mid=(left+right)/2;
	
	if(left<right)
	{
		FBI(left,mid);
		FBI(mid+1,right);
	}
	
	 int zero=0,digit=0;
	 for(int i=left;i<=right;i++)
	 {
	 	if(s[i]=='0')
	 	{
	 		zero++;
		}
		else
		{
			digit++;
		}
	 }
	 
	 if(zero>=1&&digit>=1)
	 {
	 	cout<<'F';
	 }
	 else if(zero>=1)
	 {
	 	cout<<'B';
	 }
	 else
	 {
	 	cout<<'I';
	 }
	
}

int main()
{
	int n,z;
	cin>>n;
	cin>>s;
	
	z=pow(2,n)-1;
	FBI(0,z);
	return 0;
}
