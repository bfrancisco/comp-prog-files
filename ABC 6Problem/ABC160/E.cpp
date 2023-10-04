#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<int> RED(a), GRE(b), NON(c);
    for (int i = 0; i < a; i++) cin >> RED[i];
    for (int i = 0; i < b; i++) cin >> GRE[i];
    for (int i = 0; i < c; i++) cin >> NON[i];
    sort(RED.begin(), RED.end());
    sort(GRE.begin(), GRE.end());
    sort(NON.begin(), NON.end());


    return 0;
}