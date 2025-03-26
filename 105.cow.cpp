#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 5e4 + 5;
PII a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        int x, y;
        cin >> x >> y;
        a[i].first = x + y;
        a[i].second = y;
    }
    sort(a, a + n);
    long long res = -1e18, sum = 0;
    for(int i = 0; i < n; i ++ ){
        sum -= a[i].second;
        res = max(res, sum);
        sum += a[i].first;
    }
    cout << res << endl;
    return 0;
}


