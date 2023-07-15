#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define MAX 10000010
int spf[MAX];
vector<ll> v[MAX];
int pfc[MAX];
int pref[MAX];
void sieve(){
    for (int i = 1; i < MAX; i++)
        spf[i] = i;
 
    // Separately mark all the
    // smallest prime factor of
    // every even number to be 2
    for (int i = 4; i < MAX; i = i + 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAX; i++)
 
        // If i is prime
        if (spf[i] == i) {
 
            // Mark spf for all numbers
            // divisible by i
            for (int j = i * i; j < MAX;
                 j = j + i) {
 
                // Mark spf[j] if it is
                // not previously marked
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
}
 
// Function to find the distinct
// prime factors
void DistPrime()
{
    for (int i = 1; i < MAX; i++) {
 
        int idx = 1;
        int x = i;
 
        // Push all distinct of x
        // prime factor in v[x]
        if (x != 1)
            v[i].push_back(spf[x]);
        pfc[i]++;
        x = x / spf[x];
 
        while (x != 1) {
 
            if (v[i][idx - 1]
                != spf[x]) {
 
                // Pushback into v[i]
                v[i].push_back(spf[x]);
                pfc[i]++;

                // Increment the idx
                idx += 1;
            }
 
            // Update x = (x / spf[x])
            x = x / spf[x];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    sieve();
    DistPrime();
    // for (int x = 2; x <= 10; x++) cout << pfc[x] << " "; cout << endl;/
    
    pref[1] = 0;
    pref[2] = -pfc[2];
    for (int i = 3; i < MAX; i++){
        pref[i] = pref[i-1];
        if (pfc[i]%2) pref[i]--;
        else pref[i]++;
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
    }
    
    return 0;
}