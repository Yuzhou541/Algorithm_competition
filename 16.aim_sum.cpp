#include<iostream>
using namespace std;
const int N = 100010;
int a[N], b[N];
int n, m, x;

int main()
{
	cin >> n >> m >> x;
	for(int i = 0; i < n; i++)	cin >> a[i];
	for(int j = 0; j < m; j++)	cin >> b[j];
	int i = 0, j = m - 1;
	while(a[i] + b[j] != x){
		if(a[i] + b[j] > x)	j--;
		if(a[i] + b[j] < x)	i++;
	}
	cout << i << " " << j << endl;
	return 0;
}
