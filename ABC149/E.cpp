#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n, m;
vector<ll> a, p;

pair<ll, ll> f(ll pv){
    ll shakes = 0, happy = 0;
    for (int i = 0; i < n; i++){
        if (a[i]+a[i] < pv) break;
        int l = i, r = n-1, gud;
        while (l <= r){
            // cout << "in: " << l << " " << r << endl;

            int mid = (l+r) / 2;
            if (a[i] + a[mid] >= pv) {l = mid+1; gud = mid;}
            else r = mid-1;
        }

        ll rights = gud-i;
        shakes += 1 + rights*2;
        happy += a[i]*2 + a[i]*rights + (p[gud] - p[i])*2;

        return {shakes,happy};
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    a.resize(n);
    p.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    p[0] = a[0];
    for (int i = 1; i < n; i++) p[i] = p[i-1] + a[i];
    
    
    ll l = 0, r = 2*a[0] + 10; 
    ll gud;
    while (l <= r){
        cout << "out: " << l << " " << r << endl;
        ll mid = (l+r)/2;
        pair<ll, ll> shakeshappy = f(mid);
        ll shakes = shakeshappy.first;
        ll happy = shakeshappy.second;
        cout << shakes << " " << happy << endl;
        if (shakes >= m){
            l = mid+1;
            gud = mid;
        }
        else{
            r = mid-1;
        }
    }

    pair<ll, ll> shakeshappy = f(gud);
    ll shakes = shakeshappy.first;
    ll happy = shakeshappy.second;

    cout << shakes << " " << happy << endl;
    if (shakes == m) cout << happy << endl;
    // else cout << happy - l << endl;


    return 0;
}

// 4 16
// 4 3 2 1