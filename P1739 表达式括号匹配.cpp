#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

queue < char > que;
int leftn, rightn, t;

int main() {
	
	char ch = getchar();
	while ( ch != '@' ) {
		que.push(ch);
		ch = getchar();
	}
	
	while ( !que.empty() ) {
		if ( que.front() == '(' ) {
			leftn++;
			t++;
		}
		if ( que.front() == ')' ) {
			rightn++;
			if ( t ) {
				t--;
			}
		}
		
		que.pop();
	}
	
	if ( leftn == rightn && t == 0 ) {
		cout << "YES" << endl; 
	}
	else {
		cout << "NO" << endl;
	}
	
	return 0;
}
