extern "C" int Seniorious ( int ) ;

extern "C" int Chtholly ( int n , int OvO ) {
    int left = 1 , right = n ;
    while ( right > left ) {
        int mid = ( left + right ) / 2 ;
        int result = Seniorious ( mid ) ;
        if ( result == 0 ) {
            return mid ;
        }
        else if ( result == 1 ) {
            right = mid - 1 ;
        }
        else {
            left = mid + 1 ;
        }
    }

    return left ;
}
