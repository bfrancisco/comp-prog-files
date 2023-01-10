#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double ans = 0.0, r = 380000.0;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        double x; string u;
        cin >> x >> u;

        if (u == "JPY")
            ans += x;
        else
            ans += x*r;
    }
    cout.precision(7);
    cout << fixed << ans;
    return 0;
}   