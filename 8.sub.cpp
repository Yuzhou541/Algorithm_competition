#include<iostream>
#include<vector>
using namespace std;
vector<int> A, B;

vector<int> sub(vector<int> &A, vector<int> &B){
	int t = 0;
	vector<int> C;
	for(int i = 0; i < A.size(); i++){
		t = A[i] - t;
		if(i < B.size())	t -= B[i];
		C.push_back((t + 10) % 10);
		if(t >= 0)	t = 0;
		else	t = 1;
	}
	while(C.size() > 1 && C.back() == 0)	C.pop_back();
	return C;
}
bool cmp(string a, string b){
	if(a.size() != b.size())	return a.size() > b.size();
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i])	return a[i] > b[i];
	}
}
int main()
{
	string a, b;	cin >> a >> b;
	for(int i = a.size() - 1; i >= 0; i--)	A.push_back(a[i] - '0');
	for(int j = b.size() - 1; j >= 0; j--)	B.push_back(b[j] - '0');
	if(a == b)	cout << 0;
	else{
		if(cmp(a, b)){
			vector<int> C = sub(A, B);
			for(int i = C.size() - 1; i >= 0; i--)	cout << C[i];
		}
		else{
			cout << "-";
			vector<int> C = sub(B, A);
			for(int i = C.size() - 1; i >= 0; i--)	cout << C[i];
		}
	}
	return 0;
}
