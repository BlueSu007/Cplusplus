#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

double a, b, c, d;

double f(double x){
	return a * x * x * x + b * x * x + c * x + d;
}

int main(){
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

	for(int x = -100; x < 100; x++){
		double x1 = x, x2 = x + 1;

		if(f(x1) == 0){
			printf("%.2lf ", x1);
		}
		else if((f(x) * f(x + 1)) < 0){
			while((x2 - x1) > 0.005){
				double m = (x1 + x2) / 2;
			
			  if((f(x1) * f(m)) <= 0) 
          x2 = m;
				else 
          x1 = m;
			}

			printf("%.2lf ", x1);
		}
	}

	return 0;
}
