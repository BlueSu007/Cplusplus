#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct student{
	int yw,sx,yy,zf,xh;
};

struct student a[310];
int n;

void sort()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i].zf<a[j].zf)
			{
				swap(a[i],a[j]);
			}
			else if(a[i].zf==a[j].zf)
			{
				if(a[i].yw<a[j].yw)
				{
					swap(a[i],a[j]);
				}
				else if(a[i].yw==a[j].yw)
				{
					if(a[i].xh>a[j].xh)
					{
						swap(a[i],a[j]);
					}
				}
			}
		}
	}
}

int main(){
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].yw>>a[i].sx>>a[i].yy;
		a[i].xh=i;
		a[i].zf=a[i].yw+a[i].sx+a[i].yy;
	}
	
	sort();
	
	for(int i=1;i<=5;i++){
		cout<<a[i].xh<<" "<<a[i].zf<<endl;
	}
	
	return 0;
}
