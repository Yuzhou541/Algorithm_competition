# include <iostream>
# include <cmath>
using namespace std;

int dgt(int n){
    int res = 0;
    while(n){
    	++res;
		n /= 10;
	}
    return res;
}
int cnt(int n, int i) 
{
    int res = 0, d = dgt(n);
    for (int j = 1; j <= d; ++ j){
        int p = pow(10, j - 1), l = n / p / 10, r = n % p, dj = n / p % 10;
        if (i) res += l * p; 
        if (!i && l) res += (l - 1) * p; 
        if ((dj > i) && (i || l)) res += p;
        if ((dj == i) && (i || l)) res += r + 1;
    }
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b , a){
        if (a > b) swap(a, b);
        for (int i = 0; i <= 9; ++ i) cout << cnt(b, i) - cnt(a - 1, i) << ' ';
        cout << endl;
    }
    return 0;
}


