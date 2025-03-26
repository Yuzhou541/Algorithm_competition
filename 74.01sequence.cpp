#include<iostream>
using namespace std;
const int N = 200010, mod = 1e9 + 7;
int n;
int fact[N], infact[N];

int ksm(int a, int k){
    int res = 1;
    while (k){
        if (k & 1) res = (long long)res * a % mod;
        a = (long long)a * a % mod;
        k >>= 1;
    }
    return res;
}

void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++){
        fact[i] = (long long)fact[i - 1] * i % mod;
        infact[i] = (long long)infact[i - 1] * ksm(i, mod - 2) % mod;
    }
}

int main() 
{
    init();
    cin >> n;
    int res = (long long)fact[2 * n] * infact[n] % mod * infact[n] % mod * ksm(n + 1, mod - 2) % mod;
    cout << res << endl;
    return 0;
}


