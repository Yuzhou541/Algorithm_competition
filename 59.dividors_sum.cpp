#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
const int N = 110, mod = 1e9 + 7;

int main()
{
	int n;	cin >> n;
	unordered_map<int, int>	primes;
	while(n--){
		int x;	cin >> x;
		for(int i = 2; i <= x / i; i++){
			while(x % i == 0){
				x /= i;
				primes[i]++;
			}
		}
		if(x > 1)	primes[x]++;
	}
	long long res = 1;
	for(auto p : primes){
		long long a = p.first, b = p.second;
		long long t = 1;
		while(b--)
			t = (t * a + 1) % mod;
		res = res * t % mod;
	}
	cout << res << endl;
	return 0;
}
