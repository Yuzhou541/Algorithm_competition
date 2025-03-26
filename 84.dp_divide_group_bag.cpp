#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
int v[110][110], w[110][110], f[110], s[110];

int main() 
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ){
        cin >> s[i];
        for (int j = 1; j <= s[i]; j ++ ){
            cin >> v[i][j] >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i ++ ){
        for (int j = m; j >= 1; j -- ){ 
            for (int k = 1; k <= s[i]; k ++ ){ 
                if(v[i][k] <= j){ 
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }    
    }
    cout << f[m];
    return 0;
}


