#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n; ll m;
int MAX_DARTS = 4;
vector<ll> a;
ll ans = 0;

void rb(vector<int> &s){
    if (s.size() == MAX_DARTS){
        ll total = 0;
        for (auto x : s)
            total += a[x];

        if (total <= m)
            ans = max(ans, total);
        return;
    }

    for (int i = 0; i <= n; i++){
        s.push_back(i);
        rb(s);
        s.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    a.resize(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    vector<int> s;
    rb(s);
    cout << ans << endl;

    return 0;
}