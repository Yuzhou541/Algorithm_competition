#include<iostream>
#include<cstring>
using namespace std;
const int N = 510, M = 100010;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
bool st[N];
int match[N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void init(){
	memset(h, -1, sizeof h);
}
int find(int x){
	for(int i = h[x]; i != -1; i = ne[i]){
		int j = e[i];
		if(!st[j]){
			st[j] = true;
			if(!match[j] || find(match[j])){
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	init();
	cin >> n1 >> n2 >> m;
	while(m--){
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	int res = 0;
	for(int i = 1; i <= n1; i++){
		memset(st, false, sizeof st);
		if(find(i))
			res++;
	}
	cout << res << endl;
	return 0;
}
