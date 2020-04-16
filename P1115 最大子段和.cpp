/*采用分治方法解题
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define minn -19260817
typedef long long ll;

ll a[2000001];
int fenzhi(int start,int end);

int main(){
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	cout<<fenzhi(1,n)<<endl;
	
	return 0;
}

int fenzhi(int start,int end){
	if(start==end){
		return a[start];
	}
	
	int cnt1=minn,cnt2=minn,sum=0;
	int mid=(start+end)/2;
	
	for(int i=mid;i>=start;i--){
		sum+=a[i];
		cnt1=max(sum,cnt1);
	}
	
	sum=0;
	
	for(int i=mid+1;i<=end;i++){
		sum+=a[i];
		cnt2=max(sum,cnt2);
	}
	
	return max( max( fenzhi( start, mid ), fenzhi( mid + 1, end ) ), cnt1 + cnt2 );
}
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n,maxx,sum,j;

int main(){
	scanf("%d%d",&n,&maxx);
	sum=maxx;
	
	while(--n){
		scanf("%d",&j);
		sum=sum>0? sum:0;
		
		sum+=j;
		maxx=maxx>sum? maxx:sum;
	}
	
	printf("%d",maxx);
	
	system("pause");
	return 0;
}
