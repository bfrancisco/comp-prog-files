#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;

    if (n >= 1) cout << 0 << endl;
    if (n >= 2) cout << 6 << endl;
    if (n >= 3) cout << 28 << endl;
    if (n >= 4) cout << 96 << endl;
    if (n <= 4) return 0;
    ll four, six, eight;
    four = 8;
    six = 4;
    for (ll k = 5; k <= n; k++, four += 4ll, six += 4ll){
        eight = (k-4)*(k-4);
        cout << ((k*k)*(k*k - 1ll) - 8ll - 24ll - 4ll*four - 6ll*six - 8ll*eight) / 2ll << endl;
    }
    
    return 0;
}