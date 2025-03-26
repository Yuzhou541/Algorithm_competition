#include <algorithm>
#include<iostream>
using namespace std;
const int N = 100005;
int n, res;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)	cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)	res += abs(a[i] - a[n >> 1]);
    cout << res << endl;
    return 0;
}


