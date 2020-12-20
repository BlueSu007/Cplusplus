#include<iostream>
using namespace std;

int main(){
    long long a,b,s=0,n;
    cin>>a>>b;

    for(int y=a;y<=b;y++){
        n=y;

        while(n!=0){
            if(n%10==2) s++;
            n/=10;
        }
    }

    cout<<s;

    return 0;
}
