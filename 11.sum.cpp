#include<iostream>
using namespace std;
const int N = 100010;
int a[N], s[N];
int n, m;

int main()
{
	cin >> n >> m;
	a[0] = 0, s[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	while(m--){
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
