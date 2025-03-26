#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
int g[N][N];
int dt[N];
int st[N];
int pre[N];
int n, m;

void prim(){
	memset(dt, 0x3f, sizeof(dt));
	int res = 0;
	dt[1] = 0;
	for(int i = 0; i < n; i++){
		int t = -1;
		for(int j = 1; j <= n; j++){
			if(!st[j] && (t == -1 || dt[j] < dt[t]))
				t = j;
		}
		if(dt[t] == 0x3f3f3f3f){
			cout << "impossible";
			return;
		}
		st[t] = 1;
		res += dt[t];
		for(int i = 1; i <= n; i++){
			if(dt[i] > g[t][i] && !st[i]){
				dt[i] = g[t][i];
				pre[i] = t;
			}
		}
	}
	cout << res;
}
int main()
{
	memset(g, 0x3f, sizeof(g));
	cin >> n >> m;
	while(m--){
		int a, b, w;
		cin >> a >> b >> w;
		g[a][b] = g[b][a] = min(g[a][b], w);
	}
	prim();
	return 0;
}
