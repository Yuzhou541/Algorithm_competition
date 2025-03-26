#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510, M = 100010;
int h[N], e[M], ne[M], w[M], idx;
int state[N];
int dist[N];
int n, m;

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void Dijkstra(){
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	for(int i = 0; i < n; i++){
		int t = -1;
		for(int j = 1; j <= n; j++){
			if(!state[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		}
		state[t] = 1;
		for(int j = h[t]; j != -1; j = ne[j]){
			int i = e[j];
			dist[i] = min(dist[i], dist[t] + w[j]);
		}
	}
}

int main()
{
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	while(m--){
		int a, b, w;
		cin >> a >> b >> w;
		add(a, b, w);
	}
	Dijkstra();
	if(dist[n] != 0x3f3f3f3f)	cout << dist[n];
	else	cout << "-1";
	return 0;
}

