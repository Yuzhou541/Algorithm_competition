#include<iostream>
using namespace std;
const int N = 1000010;
int a[N], q[N], n, k;

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)	cin >> a[i];
	int tt = -1, hh = 0;
	for(int i = 0; i < n; i++){
		if(hh <= tt && i - k + 1 > q[hh])	hh++;
		while(hh <= tt && a[q[tt]] >= a[i])	tt--;
		q[++tt] = i;
		if(i >= k - 1)	cout << a[q[hh]] << " ";	
	}
	cout << endl;
	tt = -1, hh = 0;
	for(int i = 0; i < n; i++){
		if(hh <= tt && i - k + 1 > q[hh])	hh++;
		while(hh <= tt && a[q[tt]] <= a[i])	tt--;
		q[++tt] = i;
		if(i >= k - 1)	cout << a[q[hh]] << " ";
	}
	return 0;
}
