#include<iostream>
using namespace std;
int dp[1005], n, t, v, w, s;

int main()
{
    cin >> n >> t;
    while(n--){
    	cin >> w >> v >> s;
    	while(s--)
    		for(int j = t; j >= w; j--)
    			dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[t];
    return 0;
}
