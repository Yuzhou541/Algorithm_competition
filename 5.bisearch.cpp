#include<iostream>
using namespace std;
const int N = 100010;
int num[N];
int n, q;

int main()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++)	cin >> num[i];
	while(q--){
		int l = 0, r = n - 1;
		int x;	cin >> x;
		while(l < r){
			int mid = l + r >> 1;
			if(num[mid] >= x)	r = mid;
			else	l = mid + 1;
		}
		if(num[l] != x)	cout << "-1 -1" << endl;
		else{
			cout << l << " ";
			int l = 0, r = n - 1;
			while(l < r){
				int mid = l + r + 1 >> 1;
				if(num[mid] <= x)	l = mid;
				else	r = mid - 1;
			}
			cout << r << endl;
		}
	}
	return 0;
}
