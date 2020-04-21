#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
int t[100000 + 5], m[100000 + 5], h[100000 + 5];
vector <int> boat[100000 + 5];

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> m[i];
		
		for(int j = 1; j <= m[i]; j++){
			int tmp;
			cin >> tmp;
			boat[i].push_back(tmp);//write passengers & boats information 
		}
	} 
	
	int left = 0;
	for(int i = 1; i <= n; i++){
		
		//if TLE ->
		while(t[i] - t[left] >= 86400){
			for(int j = 0; j < m[left]; j++){
				h[boat[left][j]]--;//minus *this id's number
				if(!h[boat[left][j]])//if haven't got *this's id(minus) ->
					ans--;//minus one id(minus anwers)
			}
			
			left++;//time-cloker move later
		}
		
		for(int j = 0; j < m[i]; j++){
			h[boat[i][j]]++;//count *this id's number
			if(h[boat[i][j]] == 1)//if haven't got *this id yet(adding) ->
				ans++;//add one id(add answers)
		}
		
		cout << ans << endl;//output answers
	}
	
	return 0;
}
