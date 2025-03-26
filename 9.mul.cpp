#include<iostream>
#include<vector>
using namespace std;
vector<int> G;

vector<int> mul(vector<int> &G, int b){
	vector<int> C;
	int t = 0;
	for(int i = 0; i < G.size() || t; i++){
		if(G.size() > i)	t += G[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while(C.size() > 1 && C.back() == 0)	C.pop_back();
	return C;
}
int main()
{
	string a;	cin >> a;
	int b;	cin >> b;
	for(int i = a.size() - 1; i >= 0; i--)	G.push_back(a[i] - '0');
	vector<int> C = mul(G, b);
	for(int i = C.size() - 1; i >= 0; i--)	cout << C[i];
	return 0;
}
