#include<iostream>
using namespace std;
int lowbit(int x){
	return x & (-x);
}

int main()
{
	int n;	cin >> n;
	while(n--){
		int res = 0;
		int x;	cin >> x;
		while(x){
			x -= lowbit(x);
			res++;
		}
		cout << res << " ";
	}
	return 0;
}
