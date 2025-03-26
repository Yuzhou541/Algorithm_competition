#include<iostream>
using namespace std;
const int N = 100010;
int p[N];
int n, m;

int find(int x){
	if(p[x] != x)	p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	p[i] = i;
	while(m--){
		int a, b;
		char op[2];
		cin >> op >> a >> b;
		if(op[0] == 'M')	p[find(a)] = find(b);
		else{
			if(find(a) == find(b))	cout << "Yes" << endl;
			else	cout << "No" << endl;
		}
	}
	return 0;
}
