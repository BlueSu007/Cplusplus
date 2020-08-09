#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , tmp , cnt , maxn ;
int a[1000000 + 5] , prime[100000000 + 5] , remember[100000000 + 5] ;
//读入
inline void input () ;
//筛质数
inline void work () ;
//标记倍数
inline void label ( int i ) ;
//输出
inline void output () ;

int main () {

    input () ;
    work () ;
    output () ;

    return 0 ;
}

//读入不解释
inline void input () {
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }
}

//筛质数
inline void work() {
    //枚举自然数
    for ( int i = 2 ; i <= n ; i++ ) {
        //如果没有合数标记
        if ( remember[i] == 0 ) {
            //那就是质数
            cnt++ , prime[cnt] = i ;
        }
        //扫荡倍数
        label (i) ;
    }
}

//标记倍数
inline void label ( int i ) {
    //枚举质数（不超过n）
    for ( int j = 1 ; j <= cnt && i * prime[j] <= n /* 计算对应合数 */ ; j++ ) {
        //标为合数
        remember[i * prime[j]] = 1 ;
        //计算直到i的平方
        if ( i % prime[j] == 0 ) {
            break ;
        }
    }
}

//输出不解释
inline void output () {
    for ( int i = 1 ; i <= m ; i++ ) {
        printf ( "%d\n" , prime[a[i]] ) ;
    }
}
