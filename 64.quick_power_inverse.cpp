#include<iostream>
using namespace std;

int quick_pow(int a, int k, int p){
	int res = 1 % p;
	while(k){
		if(k & 1){
			res = (long long)res * a % p;
		}
		k >>= 1;
		a = (long long)a * a % p;
	}
	return res;
}
int main()
{
	int n;	cin >> n;
	while(n--){
		int a, p;
		cin >> a >> p;
		int res = quick_pow(a, p - 2, p);
		if(a % p)	cout << res << endl;
		else	cout << "impossible" << endl; 
	}
	return 0;
}
