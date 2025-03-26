#include <iostream>
using namespace std;
const int N = 409, INF = 1e9;
int n, x[N], f[N][N], a[N];
int Min = INF;

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(0); 
    cin >> n;
    for(int i = 1;i <= n;++ i){
        cin >> x[i];
        a[i] = a[i - 1] + x[i];
    }
    for(int len = 1;len < n;++ len)
        for(int i = 1, j;i <= n - len;++ i){
            j = i + len;
            f[i][j] = INF;
            for(int k = i;k < j;++ k)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
            if(len == n - 1) Min = min(Min, f[i][j]);
        }
    if(Min != INF) cout << Min << endl;
    else cout << 0 << endl;
    return 0;
}


