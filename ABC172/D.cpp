#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll prime[10000001];

void sieve(int n){
    for (int p = 2; p * p <= n; p++){
        if (prime[p] == 0){
            prime[p] = 2;
            for (int i = p * p; i <= n; i += p){
                prime[i] += 2;
                if (abs(sqrt(i) * sqrt(i) - i) < 0.000001f) prime[i]--;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    prime[1] = 1;
    sieve(n);
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans += i * prime[i];
        cout << i << " " << prime[i] << endl;
    }

    cout << ans << endl;

    
    return 0;
}