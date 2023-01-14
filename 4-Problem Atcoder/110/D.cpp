#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll N, M;
vector<ll> exps;
ll mod = 1e9 + 7;
ll nCr(ll n, ll r)
{
    if (r > n) return 0LL;
    if (r * 2 > n) r = n-r;
    if (r == 0) return 1LL;

    ll result = n;
    for( int i = 2; i <= r; ++i ) {
        result *= ((n-i+1));
        result /= i;
    }
    return result;
}

void pfact(ll num){
    
    ll pushval = 0;
    while (num % 2 == 0){
        pushval++;
        num /= 2LL;
    }
    exps.push_back(pushval);

    for (ll i = 3; i * i <= num; i+=2){
        pushval = 0;
        while(num % i == 0){
            pushval++;
            num /= i;
        }
        if (pushval > 0) exps.push_back(pushval);
    }

    // prime
    if (num > 2LL){
        exps.push_back(1LL);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    pfact(M);

    ll ans = 1;
    for (auto e : exps){
        ans *= (nCr(e + N-1, N-1) % mod);
        cout << e << " ";
    }
    cout << endl;
    cout << ans % mod;
    return 0;
}