#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; double d;
    cin >> n >> d;
    int ans = 0;
    for (int i = 0; i < n; i++){
        double x, y; cin >> x >> y;
        if (pow(pow(x, 2) + pow(y, 2), 0.5) <= d)
            ans++;
    } 
    cout << ans;
    return 0;
}