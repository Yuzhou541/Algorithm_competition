#include<iostream>
using namespace std;
double esp = 1e-8;

int main()
{
	double x;	cin >> x;
	double l = -1e4, r = 1e4;
	while(r - l > esp){
		double mid = (l + r) / 2;
		if(mid * mid * mid < x)	l = mid;
		else	r = mid;
	}
	printf("%.6f", l);
	return 0;
}
