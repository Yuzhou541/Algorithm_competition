#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int h[N], hp[N], ph[N];
int mysize;

void heap_swap(int u, int v){
	swap(h[u], h[v]);
	swap(hp[u], hp[v]);
	swap(ph[hp[u]], ph[hp[v]]);
}
void down(int u){
	int t = u;
	if(2 * u <= mysize && h[t] > h[2 * u])	t = 2 * u;
	if(2 * u + 1 <= mysize && h[t] > h[2 * u + 1])	t = 2 * u + 1;
	if(u != t){
		heap_swap(u, t);
		down(t);
	}
}
void up(int u){
	if(u / 2 > 0 && h[u] < h[u / 2]){
		heap_swap(u, u / 2);
		up(u >> 1);
	}
}

int main()
{
	int n;	cin >> n;
	int m = 0;
	while(n--){
		string op;
		int k, x;
		cin >> op;
		if(op == "I"){
			cin >> x;
			m++;
			h[++mysize] = x;
			ph[m] = mysize;
			hp[mysize] = m;
			up(mysize);
		}
		else if(op == "PM")	cout << h[1] << endl;
		else if(op == "DM"){
			heap_swap(1, mysize);
			mysize--;
			down(1);
		}
		else if(op == "D"){
			cin >> k;
			int u = ph[k];
			heap_swap(u, mysize);
			mysize--;
			up(u);
			down(u);
		}
		else if(op == "C"){
			cin >> k >> x;
			h[ph[k]] = x;
			down(ph[k]);
			up(ph[k]);
		}
	}
	return 0;
}
