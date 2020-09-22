#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
	int start , end , weight , next ;
} edge[200000 + 5] ;

struct node {
	int weight , now ;
	inline bool operator < ( node tmp ) const {
		return weight > tmp.weight ;
	}
} ;

int a[100000 + 5] , vis[100000 + 5] , dis[100000 + 5] ;
int cnt , n , m , s , x , y , z ;
inline void input () ;
inline void add ( int start , int end , int weight ) ;
inline void init () ;
inline void dijkstra () ;
inline void output () ;

priority_queue < node > q ;

int main () {

	input () ;
	dijkstra () ;
	output () ;

	return 0 ;
}

inline void input () {
	scanf ( "%d %d %d" , &n , &m , &s ) ;
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d %d %d" , &x , &y , &z ) ;
		add ( x , y , z ) ;
	}
}

inline void add ( int start , int end , int weight ) {
	edge[++cnt].start = start ;
	edge[cnt].end = end ;
	edge[cnt].weight = weight ;
	edge[cnt].next = a[start] ;
	a[start] = cnt ;
}

inline void init () {
	for ( int i = 1 ; i <= n ; i++ ) {
		dis[i] = INT_MAX ;
	}
	dis[s] = 0 ;
}

inline void dijkstra () {
	init () ;
	q.push ( ( node ) { 0 , s } ) ;

	while ( !q.empty () ) {
		node x = q.top () ;
		q.pop () ;
		int start = x.now ;

		if ( vis[start] ) {
			continue ;
		}
		vis[start] = 1 ;

		for ( int i = a[start] ; i ; i = edge[i].next ) {
			int end = edge[i].end ;
			if ( dis[end] > dis[start] + edge[i].weight ) {
				dis[end] = dis[start] + edge[i].weight ;
				q.push ( ( node ) { dis[end] , end } ) ;
			}
		}
	}
}

inline void output () {
	for ( int i = 1 ; i <= n ; i++ ) {
		printf ( "%d " , dis[i] ) ;
	}
}
