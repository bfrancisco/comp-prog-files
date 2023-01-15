#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    ll x[50], y[50], xs[50], ys[50];
    
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        xs[i] = x[i];
        ys[i] = y[i];
    }
    sort(xs, xs+n);
    sort(ys, ys+n);
    
    ll ans = (xs[n-1] - xs[0]) * (ys[n-1] - ys[0]);

    // bruteforce all possible rectangles
    for (int x1 = 0; x1 < n; x1++)
        for (int x2 = x1+1; x2 < n; x2++)
            for (int y1 = 0; y1 < n; y1++)
                for (int y2 = y1+1; y2 < n; y2++){
                    ll X = xs[x2] - xs[x1];
                    ll Y = ys[y2] - ys[y1];
                    ll area = X*Y;
                    int points = 0;
                    for (int i = 0; i < n; i++){
                        if (xs[x1] <= x[i] && x[i] <= xs[x2] && ys[y1] <= y[i] && y[i] <= ys[y2]) points++;
                    }
                    if (points >= k){
                        ans = min(ans, area);
                        // cout << x1 << " " << x2  << " " << y1 << " " << y2 << endl;
                    }
                }

    cout << ans;
                    



    
    return 0;
}   