#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define N 10005
#define M 50005

struct Edge {
    int id , u , v , w ;
    Edge () : id (0) , u (0) , v (0) , w (0) {} ;

    inline bool operator < ( Edge &x ) const {
        return w > x.w ;
    }
} edge[M] ;

int n , m , q , father[N] , depth[N] , LCAfather[N][25] , vis[N] ;
int head[N * 2] , nextn[N * 2] , endn[N * 2] , weight[N * 2] , cnt , x , y , maxWeight[N][25] ;
inline void init () ;
inline int find ( int x ) ;
inline int combine ( int x , int y ) ;
inline void kruskal () ;
inline void dfs ( int cur ) ;
inline void beforeLCA () ;
inline void addEdge ( int u , int v , int w ) ;
inline void dfs ( int cur ) ;
inline int LCA ( int u , int v ) ;


int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &edge[i].u , &edge[i].v , &edge[i].w ) ;
        edge[i].id = i ;
    }
	
	kruskal () , beforeLCA () ;

    scanf ( "%d" , &q ) ;
    for ( int i = 1 ; i <= q ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        printf ( "%d\n" , LCA ( x , y ) ) ;
    }

    return 0 ;
}

inline void init () {
    for ( int i = 1 ; i <= n ; i++ ) {
        father[i] = i ;
    }
}

inline int find ( int x ) {
    if ( x != father[x] ) {
        return father[x] = find ( father[x] ) ;
    }

    return x ;
}

inline int combine ( int x , int y ) {
    int p = find (x) , q = find (y) ;
    if ( p == q ) {
        return false ;
    }
    else {
        father[p] = q ;
        return true ;
    }
}

inline void kruskal () {
    sort ( edge + 1 , edge + m + 1 ) , init () ;
    for ( int i = 1 ; i <= m ; i++ ) {
        if ( combine ( edge[i].u , edge[i].v ) == 1 ) {
            addEdge ( edge[i].u , edge[i].v , edge[i].w ) ;
            addEdge ( edge[i].v , edge[i].u , edge[i].w ) ;
        }
    }
}

inline void beforeLCA () {
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( ! vis[i] ) {
            depth[i] = 1 , dfs (i) ;
            LCAfather[i][0] = i , maxWeight[i][0] = INT_MAX ;
        }
    }

    for ( int i = 1 ; i <= 20 ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            LCAfather[j][i] = LCAfather[LCAfather[j][i - 1]][i - 1] ;
            maxWeight[j][i] = min ( maxWeight[j][i - 1] , maxWeight[LCAfather[j][i - 1]][i - 1] ) ;
        }
    }
}

inline void addEdge ( int u , int v , int w ) {
    cnt++ , nextn[cnt] = head[u] ;
    endn[cnt] = v , weight[cnt] = w ;
    head[u] = cnt ;
}

inline void dfs ( int cur ) {
    vis[cur] = true ;
    for ( int i = head[cur] ; i > 0 ; i = nextn[i] ) {
    	if ( vis[endn[i]] ) {
    		continue ;
    	}
    	
    	depth[endn[i]] = depth[cur] + 1 ;
    	LCAfather[endn[i]][0] = cur , maxWeight[endn[i]][0] = weight[i] ;
    	dfs ( endn[i] ) ;
    }
}

inline int LCA ( int u , int v ) {
	if ( find (u) != find (v) ) {
		return -1 ;
	}
    if ( depth[u] > depth[v] ) {
    	swap ( u , v ) ;
    }

	int ans = INT_MAX ;
    for ( int i = 20 ; i >= 0 ; i-- ) {
        if ( depth[LCAfather[v][i]] >= depth[u] ) {
        	ans = min ( ans , maxWeight[v][i] ) ;
            v = LCAfather[v][i] ;
        }
    }

    if ( u == v ) {
        return ans ;
    }

    for ( int i = 20 ; i >= 0 ; i-- ) {
        if ( LCAfather[u][i] != LCAfather[v][i] ) {
            ans = min ( ans , min ( maxWeight[u][i] , maxWeight[v][i] ) ) ;
            u = LCAfather[u][i] ;
            v = LCAfather[v][i] ;
        }
    }

    ans = min ( ans , min ( maxWeight[u][0] , maxWeight[v][0] ) ) ;
    return ans ;
}
