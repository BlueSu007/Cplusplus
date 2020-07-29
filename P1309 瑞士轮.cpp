#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

long long n , r , q ;
struct competitor {
	long long fenshu ;
	long long nengli ;
	long long bianhao ;
} a[200010] , win[200010] , lose[200010] ;

inline bool cmp ( struct competitor x , struct competitor y ) ;
inline void fenzhi() ;
inline void moni() ;

int main(){
	
	//input
	scanf ( "%lld %lld %lld" , &n , &r , &q ) ;
	n *= 2 ;
	
	for ( long long i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i].fenshu ) ; 
		a[i].bianhao = i ;
	}
	
	for ( long long i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i].nengli ) ;
	}
	
	//sort competitors
	sort ( a + 1 , a + 1 + n , cmp ) ;
	
	//while compete
	while ( r > 0 ) {
		//who wins? score?
		moni() ;
		//sort competitors
		fenzhi() ;
		//compete round minus 1
		r-- ;
	}
	
	//output the competitor's id we want to know
	printf ( "%lld" , a[q].bianhao ) ;
	
	return 0;
}

//algorithm-sort subfunction
bool cmp ( competitor x , competitor y ) {
	if ( x.fenshu == y.fenshu ) {
		return x.bianhao < y.bianhao ;
	}
	else {
		return x.fenshu > y.fenshu ;
	}
}

void fenzhi() {
	
	//merge
	long long i , j , k ;
	i = j = k = 1 ;
	
	while ( i <= n / 2 && j <= n / 2 ) {
		if ( win[i].fenshu > lose[j].fenshu ) {
			a[k++] = win[i++] ;
		}
		else if ( win[i].fenshu == lose[j].fenshu ) {
			if ( win[i].bianhao < lose[j].bianhao )
				a[k++] = win[i++] ;
			else
				a[k++] = lose[j++] ;
		}
		else {
			a[k++] = lose[j++] ;
		}
	}
	
	while ( i <= n / 2 )	a[k++] = win[i++] ;
	while ( j <= n / 2 )	a[k++] = lose[j++] ;
}

void moni() {
	
	long long cnt = 1 , i = 1 , j = 1 ;
	while ( cnt <= n ) {
		//if win
		if ( a[cnt].nengli > a[cnt + 1].nengli ) {
			//score plus
			a[cnt].fenshu++ ;
			//register winner
			win[i] = a[cnt] ;
			//register loster
			lose[j] = a[cnt + 1] ;
		}
		//if lose
		else {
			//like before
			a[cnt + 1].fenshu++ ;
			win[i] = a[cnt + 1] ;
			lose[j] = a[cnt] ;
		}
		
		i++ , j++ , cnt += 2 ;
	}
}

/*
 * Problem: Time Limit Exceeded
 * Author: RunHe Su
 * Lang: C / C++
 Please help me, thanks.
*/
