#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> a(100010, vector<int>(2, 0));
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        a[i][0] = l, a[i][1] = r;
    }
    sort(a.begin(),a.begin() + n);
    priority_queue<int, vector<int>, greater<int>> s;
    for(int i = 0; i < n; i++){
        if(s.empty() || s.top() >= a[i][0]){
            s.push(a[i][1]);
        }
        else{
            s.pop();
            s.push(a[i][1]);
        }
    }
    cout << s.size() << endl;
    return 0;
}


