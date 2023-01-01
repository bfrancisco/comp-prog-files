#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> ar;
ll db[10000000];
ll n, k;
int bisearch(ll val){
    int l, r, m;
    l = 0;
    r = n-1;

    while(r-l > 1){
        m = (r+l) / 2;
        if (ar[m] < val) l = m;
        else if (ar[m] > val) r = m;
        else return ar[m];
    }
    // cout << l << " " << r << endl;
    if (ar[r] < k) return ar[r];
    return ar[l];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;


    ll index = 0;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        ar.push_back(index);
        db[index] = a;
        index += b;
    }
    // for (auto x : ar) cout << x << " ";
    // cout << endl;
    // cout << db[0] << " " << db[1] << " " << db[3] << endl;
    // cout << bisearch(k) << endl;
    cout << db[bisearch(k-1)];
    return 0;
}