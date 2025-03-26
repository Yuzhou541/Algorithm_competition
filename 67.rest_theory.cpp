#include <cstdio>
#include <iostream>
#include<cmath>
using namespace std;
int n;

long long exgcd(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }

    long long d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
long long inline mod(long long a, long long b){
    return ((a % b) + b) % b;
}
int main(){
    cin >> n;
    long long a1, m1;
    cin >> a1 >> m1;
    for(int i = 1; i < n; i++){
        long long a2, m2, k1, k2;
        cin >> a2 >> m2;
        long long d = exgcd(a1, -a2, k1, k2);
        if((m2 - m1) % d){
			cout << "-1" << endl; 
			return 0; 
		}
        k1 = mod(k1 * (m2 - m1) / d, abs(a2 / d));
        m1 = k1 * a1 + m1;
        a1 = abs(a1 / d * a2);
    }
    cout << m1 << endl;
    return 0;
}


