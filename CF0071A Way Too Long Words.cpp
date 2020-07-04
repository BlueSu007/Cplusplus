#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    
    int n, lenth;
    string s;
    cin >> n;
    
    while(n--){
    	cin >> s;
    	lenth = s.size();
    	if(lenth > 10)
    		cout << s[0] << lenth - 2 << s[lenth - 1] << endl;
    	else
    		cout << s << endl;
	}
    
    return 0;
}
