#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int h[N], mysize;
int n, m;

void down(int u){
	int t = u;
	if(2 * u <= mysize && h[t] > h[2 * u])	t = 2 * u;
	if(2 * u + 1 <= mysize && h[t] > h[2 * u + 1])	t = 2 * u + 1;
	if(u != t){
		swap(h[u], h[t]);
		down(t);
	}
}

int main()
{
	cin >> n >> m;
	mysize = n;
	for(int i = 1; i <= n; i++)	cin >> h[i];
	for(int i = n / 2; i; i--)	down(i);
	while(m--){
		cout << h[1] << " ";
		h[1] = h[mysize--];
		down(1);
	}
	return 0;
}
