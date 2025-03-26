#include<iostream>
using namespace std;
const int N = 1e5 + 5, P = 131;
long long h[N], p[N];

long long query(int l, int r){
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	int n, m;
	cin >> n >> m;
	string x;
	cin >> x;
	p[0] = 1;
	h[0] = 0;
	for(int i = 0; i < n; i++){
		p[i + 1] = p[i] * P;
		h[i + 1] = h[i] * P + x[i];
	}
	while(m--){
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if(query(l1, r1) == query(l2, r2))	cout << "Yes" << endl;
		else	cout << "No" << endl;
	}
	return 0;
}
