#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int T;	cin >> T;
	while(T--){
		int n;	cin >> n;
		vector<int> res;
		for(int i = 1; i <= n / i; i++){
			if(n % i == 0){
				res.push_back(i);
				if(n / i != i){
					res.push_back(n / i);
				}
			}
		}
		sort(res.begin(), res.end());
		for(auto x : res)	cout << x << " ";
		cout << endl;
	}
	return 0;
}
