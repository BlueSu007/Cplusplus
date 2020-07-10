#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
using namespace std;

int n, len, tmp;
int heap[50000 + 5];
inline void push(int x);
inline void pop();
inline int read_();

int main(){
	
	ios::sync_with_stdio(false);
	n = read_();
	
	for(register int i = 1; i <= n; i++){
		tmp = read_();
		push(tmp);
	}
	
	long long ans = 0;
	
	while(len >= 2){
		int tmp1 = heap[1];
		pop();
		int tmp2 = heap[1];
		pop();
		
		ans += (tmp1 + tmp2);
		push(tmp1 + tmp2);
	}
	
	cout << ans << endl;
	
	return 0;
}

inline int read_(){
	
	int f = 1, x = 0;
	char ch = getchar();
	
	while(!isdigit(ch)){
		if(ch == '-')
			f = -1;
		
		ch = getchar();
	}
	
	while(isdigit(ch)){
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	
	return f * x; 
}

inline void push(int x){
	
	/*Sort by small root heap*/
	
	int son, tmp;
	len++;
	
	heap[len] = x;
	son = len;
	
	while(son != 1 && (heap[son / 2] > heap[son])){
		tmp = heap[son / 2];
		heap[son / 2] = heap[son];
		heap[son] = tmp;
		son = son / 2;
	}
}

inline void pop(){
	
	/*Sort by small root heap*/
	
	int parent = 1, son, tmp;
	heap[1] = heap[len];
	len--;
	
	while(parent * 2 <= len){
		if(parent * 2 + 1 > len || (heap[parent * 2] < heap[parent * 2 + 1]))
			son = parent * 2;
		else
			son = parent * 2 + 1;
		
		if(heap[parent] > heap[son]){
			tmp = heap[parent];
			heap[parent] = heap[son];
			heap[son] = tmp;
			parent = son;
		}
		else
			return ;
	}
}
