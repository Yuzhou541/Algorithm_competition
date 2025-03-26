#include<iostream>
using namespace std;
int n, x, y;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int z = x;
    x = y;
    y = z - a / b * y;
    return d;
}

int main()
{
    cin >> n;
    while (n --)
    {
        int a, b, m;
        cin >> a >> b >> m;
        int d = exgcd(a, m, x, y);
        if (b % d) cout << "impossible" << endl;
        else 
        {
            x = (long long)x * b / d % m;
            cout << x << endl;
        }
    }
    return 0;
}


