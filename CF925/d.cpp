#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MXN = 32000;
bool prime[MXN + 1];

void sieve(){
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= MXN; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= MXN; i += p)
                prime[i] = false;
        }
    }
}

void solve(){

    int n, x, y;
    cin >> n >> x >> y;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    sieve();
    int ps = 0;
    for (int i = 0; i <= MXN; i++) if (prime[i]) ps++;
    cout << ps << endl;

    int t;
    while (t--) solve();
    
    return 0;
}