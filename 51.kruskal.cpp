#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
int p[N];
struct E{
	int a;
	int b;
	int w;
	bool operator < (const E& rhs){
		return this->w < rhs.w;
	}
}edg[N * 2];
int res = 0;
int n, m, cnt = 0;
int find(int a){
	if(p[a] != a)	p[a] = find(p[a]);
	return p[a];
}
void kruskal(){
	for(int i = 1; i <= m; i++){
		int pa = find(edg[i].a);
		int pb = find(edg[i].b);
		if(pa != pb){
			res += edg[i].w;
			p[pa] = pb;
			cnt++;
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	p[i] = i;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edg[i] = {a, b, c};
	}
	sort(edg + 1, edg + m + 1);
	kruskal();
	if(cnt < n - 1)
		cout << "impossible";
	else	cout << res;
	return 0;
}
