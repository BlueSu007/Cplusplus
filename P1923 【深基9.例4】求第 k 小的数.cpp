#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[5000000 + 5];
int n, k;

inline void quick_sort(int left, int right);

int main(){

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick_sort(0, n - 1);

    return 0;
} 

inline void quick_sort(int left, int right){
    int i = left, j = right;
    int key = a[(left + right) / 2];

    while(i <= j){
        while(a[j] > key)
            j--;

        while(a[i] < key)
            i++;

        if(i <= j)
            swap(a[i], a[j]), i++, j--;
    }

    if(k <= j)
    	quick_sort(left, j);
    else if(i <= k)
    	quick_sort(i, right);
    else{
    	cout << a[j + 1] << endl;
		return;
    }
}
