#include <iostream>
using namespace std;

struct student{
	char name[20];
	int qm,py;
	char gb,xb;
	int lw;
	int jxj=0;
};

int main(){
	int n,sum=0;
	cin>>n;
	
	student a[n];
	
	for(int i=0;i<n;i++){
		cin>>a[i].name >> a[i].qm >> a[i].py >> a[i].gb 
		>> a[i].xb >> a[i].lw;
	}
	
	for(int i=0;i<n;i++){
		if(a[i].qm>80&&a[i].lw>=1){
			a[i].jxj+=8000;
		}
		
		if(a[i].qm>85&&a[i].py>80){
			a[i].jxj+=4000;
		}
		
		if(a[i].qm>90){
			a[i].jxj+=2000;
		}
		
		if(a[i].qm>85&&a[i].xb=='Y'){
			a[i].jxj+=1000;
		}
		
		if(a[i].py>80&&a[i].gb=='Y'){
			a[i].jxj+=850;
		}
		
		sum+=a[i].jxj;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].jxj<a[j].jxj){
				swap(a[i],a[j]);
			}
		}
	}
	
	cout<<a[0].name<<endl<<a[0].jxj<<endl<<sum;
	
	return 0;
}
