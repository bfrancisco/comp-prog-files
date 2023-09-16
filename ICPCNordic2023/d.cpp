#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    if (n == 1) {
        cout << "1 1" << endl;
        return 0;
    }
    int x = n-1;
    int ax = 1e9, ay = 1e9;
    double hi = 1e9;
    for (int y = 1; y <= n; y++){
        double val = pow((double)x*(double)x + (double)y*(double)y, 1/2);
        if (val < hi && val < n){
            hi = val;
            ax = x;
            ay = y;
        }
    }
    cout << ax << " " << ay << endl;

    return 0;
}