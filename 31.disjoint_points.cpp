#include<iostream>
using namespace std;
const int N = 100010;
int n, m, p[N], s[N];
int find(int x){
	if(p[x] != x)	p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	p[i] = i, s[i] = 1;
	while(m--){
		char op[2];
		int a, b;
		cin >> op;
		if(op[0] == 'C'){
			cin >> a >> b;
			if(find(a) == find(b))	continue;
			s[find(b)] += s[find(a)];
			p[find(a)] = find(b);
		}
		else if(op[1] == '1'){
			cin >> a >> b;
			if(find(a) == find(b))	cout << "Yes" << endl;
			else	cout << "No" << endl;
		}
		else{
			cin >> a;
			cout << s[find(a)] << endl;
		}
	}
	return 0;
}
