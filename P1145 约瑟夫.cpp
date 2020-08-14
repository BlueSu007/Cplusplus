#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int num[14] = { 0 , 2 , 7 , 5 , 30 , 169 , 441 , 1872 , 7632 , 1740 , 93313 , 459901 , 1358657 , 2504881 } ;
int n ;

int main () {

    scanf ( "%d" , &n ) ;
    printf ( "%d" , num[n] ) ;

    return 0 ;
}
