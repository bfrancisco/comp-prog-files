#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f(ll n){
    return n*(n+1)/2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    map<int, int> bank;
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r;
    for (r = 0; r < n; r++){
        if (bank.size() == k)
            break;
        if (bank.find(a[r]) == bank.end())
            bank[a[r]] = 1;
        else
            bank[a[r]]++;
    }
    ans += f(r);
    for (; r < n; r++){
        if (bank.find(a[r]) == bank.end() && bank.size() == k){
            while (bank.size() == k){
                bank[a[l]]--;
                if (bank[a[l]] == 0)
                    bank.erase(a[l]);
                l++;
            }
            bank[a[r]] = 1;
            ans += r-l+1;
        }
        else{
            ans += r-l+1;
            bank[a[r]]++;
        }
    }
    cout << ans << endl;
    

    return 0;
}