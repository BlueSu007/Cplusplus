#include<cstdio>
using namespace std;

int s[105],k[10005][105];

int main(){
    int n,m,ss,kk,count=0,i,max=0,x,j;
    scanf("%d%d",&n,&m);
    
    m=m*1.5;
    
    for(i=0;i<n;i++){
        scanf("%d%d",&kk,&ss);
        
        k[kk][ss]++;
        s[ss]++;
    }
    
    for(i=100;count<m;i--)
        count+=s[i];
        
    printf("%d %d\n",i+1,count);
    
    x=i+1;
    
    for(i=100;i>=x;i--)
        for(j=1000;j<=10000;j++)
            if(k[j][i]) printf("%d %d\n",j,i);
            
    return 0;
}
