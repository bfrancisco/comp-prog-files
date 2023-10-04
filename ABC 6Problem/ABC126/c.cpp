#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);

    int n, k; cin >> n >> k;
    double ans = 0;
    vector<double> pw(50);
    pw[0] = 0.5;
    double dn = n;
    for (int i = 1; i < 50; i++) {
        pw[i] = pw[i-1] * 0.5;
    }

    for (int i = 1; i <= n; i++){
        if (i == k) break;
        int sc = i;
        int ind = 0;
        while (sc < k){
            sc *= 2;
            ind++;
        }
        ans += (1.0/dn) * pw[ind-1];
    }

    if (n >= k){
        ans += (n-k+1) * (1.0/dn);
    }

    cout << setprecision(18) << ans << endl;

    return 0;
}