#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool prime[200001];

void sieve(int n){
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++){
        if (prime[p]){
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x; cin >> x;
    sieve(200000);
    while(!prime[x]) x++;
    cout << x << endl;
    
    return 0;
}