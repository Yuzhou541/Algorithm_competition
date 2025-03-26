#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N  = 100010;
vector<vector<int>> a(N,vector<int>(2,0));
int n;

int main()
{
    cin >> n;
    for(int i = 0; i< n; i++){
        int l, r;
        cin >> l >> r;
        a[i][0] = l;
        a[i][1] = r;
    }
    sort(a.begin(), a.begin() + n, [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
    int res = 0, end = -1e9 - 10;
    for(int i = 0; i < n; i++){
        if(end >= a[i][0] && end <= a[i][1]) 
            continue;
        else{
            res++;
            end = a[i][1];
        }
    }
    cout << res;
    return 0;
}



