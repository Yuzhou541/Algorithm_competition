#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
int n, m;
bool st[N];

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int spfa(){
	queue<PII> q;
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	q.push({0, 1});
	st[1] = true;
	while(q.size()){
		PII p = q.front();
		q.pop();
		int t = p.second;
		st[t] = false;
		for(int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[t] + w[i]){
				dist[j] = dist[t] + w[i];
				if(!st[j]){
					st[j] = true;
					q.push({dist[j], j});
				}
			}
		}
	}
	return dist[n];
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	int res = spfa();
	if(res == 0x3f3f3f3f)	cout << "impossible" << endl;
	else	cout << res;
	return 0;
}

