#include <cstdio>
#include <algorithm>
using namespace std;

struct day{
	int date,id;
};

bool cmp(day x,day y){
	return x.date>y.date;
}

int main(){
	int a,b,flag=0;
	struct day c[8];
	
	for(int i=1;i<=7;i++){
		scanf("%d%d",&a,&b);
		c[i].date=a+b;
		c[i].id=i;
		
		if(c[i].date>8){
			flag=1;
		}
	}
	
	sort(c+1,c+1+7,cmp);
	
	if(!flag){
		printf("0");
	}else{
		printf("%d",c[1].id);
	}
	
	return 0;
}
