#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[10000000 + 5] , box[10000000 + 5] , tmp[10000000 + 5] , maxn , minn ;
inline void reverseArray () ;
inline void print () ;
inline void selectSort () ;
inline void bubleSort () ;
inline void insertSort () ;
inline void boxSort () ;
inline void quickSort ( int leftn , int rightn ) ;
inline void separate ( int leftn , int rightn ) ;
inline void merge ( int leftn , int mid , int rightn ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        box[a[i]] ++ ;
        maxn = max ( a[i] , maxn ) ;
        minn = min ( a[i] , minn ) ;
    }

    separate ( 1 , n ) ;
    print () ;
    reverseArray () ;
    print () ;

    return 0 ;
}

inline void reverseArray () {
    int i = 1 , j = n ;
    while ( i < j ) {
        swap ( a[i] , a[j] ) ;
        i++ , j-- ;
    }
}

inline void print () {
    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d " , a[i] ) ;
    }
    printf ( "\n" ) ;
}

inline void selectSort () {
    int minn ;
    for ( int i = 1 ; i <= n ; i++ ) {
        minn = i ;
        for ( int j = i + 1 ; j <= n ; j++ ) {
            if ( a[j] < a[minn] ) {
                minn = j ;
            }
        }

        if ( minn != i ) {
            swap ( a[minn] , a[i] ) ;
        }
    }
}

inline void bubleSort () {
    int flag , i = 1 ;
    do {
        flag = true ;
        for ( int j = 1 ; j <= n - i ; j++ ) {
            if ( a[j] > a[j + 1] ) {
                swap ( a[j] , a[j + 1] ) ;
                flag = false ;
            }
        }
        i++ ;

    } while ( ! flag ) ;
}

inline void insertSort () {
    int x , j ;
    for ( int i = 2 ; i <= n ; i++ ) {
        x = a[i] , j = i - 1 ;
        while ( x < a[j] ) {
            a[j + 1] = a[j] ;
            j-- ;
        }

        a[j + 1] = x ;
    }
}

inline void boxSort () {
    for ( int i = minn ; i <= maxn ; i++ ) {
        for ( int j = 1 ; j <= box[i] ; j++ ) {
            printf ( "%d " , i ) ;
        }
    }
    printf ( "\n" ) ;

    for ( int i = maxn ; i >= minn ; i-- ) {
        for ( int j = 1 ; j <= box[i] ; j++ ) {
            printf ( "%d " , i ) ;
        }
    }
    printf ( "\n" ) ;
}

inline void quickSort ( int leftn , int rightn ) {
    if ( leftn > rightn ) {
        return ;
    }

    int i = leftn , j = rightn , tmp = a[leftn] ;

    while ( i != j ) {
        while ( a[j] >= tmp && i < j ) {
            j-- ;
        }
        while ( a[i] <= tmp && i < j ) {
            i++ ;
        }

        if ( i < j ) {
            swap ( a[i] , a[j] ) ;
        }
    }

    swap ( a[leftn] , a[i] ) ;
    quickSort ( leftn , i - 1 ) ;
    quickSort ( i + 1 , rightn ) ;
}

inline void separate ( int leftn , int rightn ) {
    if ( leftn < rightn ) {
        int mid = ( leftn + rightn ) >> 1 ;
        separate ( leftn , mid ) ;
        separate ( mid + 1 , rightn ) ;
        merge ( leftn , mid , rightn ) ;
    }
}

inline void merge ( int leftn , int mid , int rightn ) {
    int i = leftn , j = mid + 1 , k = 0 ;
    while ( i <= mid && j <= rightn ) {
        if ( a[i] <= a[j] ) {
            tmp[k++] = a[i++] ;
        }
        else {
            tmp[k++] = a[j++] ;
        }
    }

    while ( i <= mid ) {
        tmp[k++] = a[i++] ;
    }

    while ( j <= rightn ) {
        tmp[k++] = a[j++] ;
    }

    for ( i = 0 ; i < k ; i++ ) {
        a[leftn + i] = tmp[i] ;
        // cout << tmp[i] << " " ;
    }
    // cout << endl ;
}
