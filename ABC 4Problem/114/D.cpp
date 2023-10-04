#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int legendre(int n, int p){
    // returns largest power of p that divides n!
    int p_power_e = p;
    int ret = 0;
    while (n > p_power_e){
        ret += n / p_power_e;
        p_power_e *= p;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int m = primes.size();
    int db[100];
    for (auto p : primes) db[p] = 0;

    int n; cin >> n;

    for (auto p : primes){
        if (p > n) break;
        db[p] = legendre(n, p);
    }

    int ans = 0;
    // a^74
    for (auto p : primes){
        if (db[p] >= 74) ans++;
    }

    // a^4 * b^4 * c^2
    for (int i = 0; i < m; i++){
        for (int j = i+1; j < m; j++){
            for (int k = 0; k < m; k++){
                if (i == k || j == k) continue;
                if (db[primes[i]] >= 4 && db[primes[j]] >= 4 && db[primes[k]] >= 2){
                    ans++;
                }
            }
        }
    }

    // a^24 * b^2
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (i==j) continue;
            if (db[primes[i]] >= 24 && db[primes[j]] >= 2){
                ans++;
            }
        }
    }

    // a^14 * a^2
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (i==j) continue;
            if (db[primes[i]] >= 14 && db[primes[j]] >= 4){
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}