#include <iostream>
using namespace std;

int a[30][3];

void preorder(char root)
{
	if(root!='*')
	{
		cout<<root;
		preorder(a[root][0]);
		preorder(a[root][1]);
	}
}

int main()
{
	int n;
	cin>>n;
	char x,y,z;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		if(i==0){
			a[0][0]=x;
		}
		a[x][0]=y;
		a[x][1]=z;
	}
	
	preorder(a[0][0]);
	
	return 0;
}
