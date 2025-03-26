#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 310;
int n, m; 
int f[N][N]; 
int h[N][N]; 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dp(int x,int y){
    int &v = f[x][y]; 
    if(v != -1) return v; 
    v = 1; 
    for(int i = 0; i < 4; i++){ 
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && h[x][y] > h[xx][yy]){
            v = max(v, dp(xx, yy) + 1);
        } 
    }
    return v; 
}
int main()
{
    cin >> n >> m; 
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> h[i][j]; 
        }
    }
    memset(f, -1, sizeof f);
    int res = 0; 
    for(int i = 1;i <= n;i ++){
        for(int j = 1; j <= m; j++){
            res = max(res, dp(i, j)); 
        }
    }
    cout << res << endl;
    return 0;
}


