#include<iostream>
using namespace std;
const int N = 100010;
int q[N], hh = 0, tt = -1;

int main()
{
	string c;
	int m, x;	cin >> m;
	while(m--){
		cin >> c;
		if(c == "push"){
			cin >> x;
			q[++tt] = x;
		}
		else if(c == "pop"){
			hh++;
		}
		else if(c == "empty"){
			if(tt >= hh)	cout << "NO" << endl;
			else	cout << "YES" << endl;
		}
		else	cout << q[hh] << endl;
	}
	return 0;
}
