#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll T;
vector<ll> sa, sb;

ll void

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    cin >> T;
    vector<ll> A;

    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        if (x <= T) A.push_back(x);
    }
    n = A.size();

    vector<int> va, vb;

    int m = n/2;
    for (int i = 0; i < n; i++){
        if (i < m) va.push_back(A[i]);
        else vb.push_back(A[i]);
    }

    int na = va.size(), nb = vb.size();

    // first set
    for (int mask = 0; mask < (1<<na); mask++){
        ll total = 0;
        for (int i = 0; i < na; i++){
            if (mask & (1<<i)) total += va[i];
        }
        if (total <= T)
            sa.push_back(total);
    }

    // second set
    for (int mask = 0; mask < (1<<nb); mask++){
        ll total = 0;
        for (int i = 0; i < nb; i++){
            if (mask & (1<<i)) total += vb[i];
        }
        if (total <= T)
            sb.push_back(total);
    }

    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    // print
    for (auto x : sa) cout << x << " ";
    cout << endl;
    for (auto x : sb) cout << x << " ";
    cout << endl;

    ll mx = -1;

    for (auto si : sa){
        ll sj = bsearch(si);
        
        cout << si << " " << sj << endl;
        if (si + sj <= T){
            mx = max(mx, si + sj);
            // cout << si << " " << sj << endl;
        }
    }

    cout << mx << endl;


    return 0;
}