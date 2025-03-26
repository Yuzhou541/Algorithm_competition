#include<iostream>
using namespace std;
const int N = 100010;
int stk[N], tt = 0;

int main()
{
	string c;
	int x, m;	cin >> m;
	while(m--){
		cin >> c;
		if(c == "push"){
			cin >> x;
			stk[++tt] = x;
		}
		else if(c == "pop"){
			tt--;
		}
		else if(c == "empty"){
			if(tt > 0)	cout << "NO" << endl;
			else	cout << "YES" << endl;
		}
		else	cout << stk[tt] << endl;
	}
	return 0;
}
