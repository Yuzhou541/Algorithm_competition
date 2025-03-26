#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int n;
int a[N];

int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)	cin >> a[i];
    sort(a, a + n);
    long long res = 0, t= 0;
    for (int i = 0; i < n; i++){
        res += t;
        t += a[i];
    }
    cout << res << endl;
    return 0;
}


