#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res ^= x;
    }
    if(res == 0)	cout << "No" << endl;
    else	cout << "Yes" << endl;
}


