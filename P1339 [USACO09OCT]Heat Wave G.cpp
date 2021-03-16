#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 200025
int head[LEN] , distancen[LEN] , cnt ;
int p , n , m , s , t , u , v , w ;
inline void addEdge ( int u , int v , int w ) ;
inline void dijkstra () ;

struct node {
    int endn , nextn , weight ;
} edge[LEN << 1] ;

struct Tree {
    int minWeight , minPos ;
} ;

struct SegmentTree {
    Tree sum[LEN << 2] ;
    int leftn[LEN << 2] , rightn[LEN << 2] ;

    inline void modify ( int x ) {
        sum[x].minWeight = min ( sum[x << 1].minWeight , sum[x << 1 | 1].minWeight ) ;
        sum[x].minPos = ( sum[x << 1].minWeight < sum[x << 1 | 1].minWeight ) ? sum[x << 1].minPos : sum[x << 1 | 1].minPos ;
        /* if ( sum[x << 1].minWeight < sum[x << 1 | 1].minWeight ) {
            sum[x].minPos = sum[x << 1].minPos ;
        }
        else {
            sum[x].minPos = sum[x << 1 | 1].minPos ;
        }
        */
        return ;
    }

    inline void build ( int k , int leftBound , int rightBound ) {
        leftn[k] = leftBound , rightn[k] = rightBound ;
        if ( leftBound == rightBound ) {
            sum[k].minWeight = leftBound == s ? 0 : INT_MAX ;
            sum[k].minPos = leftBound ;
            return ;
        }

        int mid = ( leftBound + rightBound ) >> 1 ;
        // cout << "Error1 { " ;
        build ( k << 1 , leftn[k] , mid ) ;
        // cout << " } Error2 { " ;
        build ( k << 1 | 1 , mid + 1 , rightn[k] ) ;
        // cout << " } Error3 { " ;
        modify (k) ;
        // cout << " } " ;
        return ;
    }

    inline void update ( int k , int pos , int x , int leftBound , int rightBound ) {
        if ( leftBound == rightBound ) {
            sum[k].minWeight = x ;
            return ;
        }

        int mid = ( leftBound + rightBound ) >> 1 ;
        if ( pos <= mid ) {
            // cout << "Error1 { " ;
            update ( k << 1 , pos , x , leftBound , mid ) ;
            // cout << " } " ;
        }
        else {
            // cout << "Error2 { " ;
            update ( k << 1 | 1 , pos , x , mid + 1 , rightBound ) ;
            // cout << " } " ;
        }

        modify (k) ;
        return ;
    }
} tree ;

int main () {

    scanf ( "%d %d %d %d" , &n , &m , &s , &t ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &u , &v , &w ) ;
        addEdge ( u , v , w ) ;
        addEdge ( v , u , w ) ;
    }

    // cout << "BreakPoint1" << endl ;
    tree.build ( 1 , 1 , n ) ;
    // cout << "BreakPoint2" << endl ;
    dijkstra () ;
    // cout << "BreakPoint3" << endl ;

    printf ( "%d" , distancen[t] ) ;
    return 0 ;
}

inline void addEdge ( int u , int v , int w ) {
    edge[++cnt].nextn = head[u] , head[u] = cnt ;
    edge[cnt].endn = v , edge[cnt].weight = w ;
}

inline void dijkstra () {
    for ( int i = 1 ; i <= n ; i++ ) {
        distancen[i] = INT_MAX ;
    }
    distancen[s] = 0 ;

    while ( tree.sum[1].minWeight < INT_MAX ) {
        int x = tree.sum[1].minPos ;
        // cout << "Error4: " ;
        tree.update ( 1 , x , INT_MAX , 1 , n ) ;
        for ( int i = head[x] ; i ; i = edge[i].nextn ) {
            int y = edge[i].endn ;
            // cout << "ERR_NUM: " << i << " " ;
            if ( distancen[y] > distancen[x] + edge[i].weight ) {
                // cout << i << " " ;
                distancen[y] = distancen[x] + edge[i].weight ;
                tree.update ( 1 , y , distancen[x] + edge[i].weight , 1 , n ) ;
            }
        }

        // printf ( "\n" ) ;
        // for ( int i = 1 ; i <= 4 * n ; i++ ) {
            // printf ( "%d " , tree.sum[i].minWeight ) ;
        // }
        // printf ( "\n" ) ;
    }
}
