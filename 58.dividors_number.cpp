#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int mod = 1e9 + 7;

int main()
{
	int T;	cin >> T;
	unordered_map<int, int> h;
	while(T--){
		int n;	cin >> n;
		for(int i = 2; i <= n / i; i++){
			while(n % i == 0){
				h[i]++;
				n = n / i;
			}
		}
		if(n > 1)	h[n]++;
	}
	long long res = 1;
	for(auto iter = h.begin(); iter != h.end(); iter++){
		res = res * (iter->second + 1) % mod;
	}
	cout << res;
	return 0;
}

