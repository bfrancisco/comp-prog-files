#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> a(5);
    for (int i = 0; i < 5; i++)
        cin >> a[i];

    int mn = 1e9;
    int mnv = 1e9;
    for (auto e : a){
        int mod = (e%10==0 ? 10 : e%10);
        if (mod <= mn){
            mn = mod;
            mnv = e;
        }
    }

    int good = 0;
    int ans = 0;
    // cout << mnv << endl;
    for (auto e : a){
        if (e == mnv && !good){
            good = 1;
            ans += e;
        }
        else{
            ans += (e%10==0 ? e : e + 10 - (e%10));
        }
    }

    cout << ans << endl;
    
    return 0;
}