#include<iostream>
using namespace std;
const int N = 5e4 + 10;
int p[N], l[N], res;

int find(int x){
	if(p[x] != x){
		int u = find(p[x]);
		l[x] += l[p[x]];
		p[x] = u;
	}
	return p[x];
}

int main()
{
	int n, m;	cin >> n >> m;
	for(int i = 1; i <= n; i++)	p[i] = i;
	while(m--){
		int op, x, y;
		cin >> op >> x >> y;
		if(x > n || y > n)	res++;
		else{
			int px = find(x), py = find(y);
			if(op == 1){
				if(px == py && (l[x] - l[y]) % 3)	res++;
				else if(px != py){
					p[px] = py;
					l[px] = l[y] - l[x];
				}
			}
			else{
				if(px == py && (l[x] - l[y] - 1) % 3)	res++;
				else if(px != py){
					p[px] = p[y];
					l[px] = l[y] - l[x] + 1;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
