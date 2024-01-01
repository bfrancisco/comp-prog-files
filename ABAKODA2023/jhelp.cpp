#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define MAXN 50000001
 
// stores smallest prime factor for every number
int spf[MAXN];
 
void sieve(){
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
 
    for (int i = 4; i < MAXN; i+=2) 
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i*i; j < MAXN; j+=i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getf(int x){
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
 
// driver program for above function
int main(){
    // precalculating Smallest Prime Factor
    sieve();
    int x; cin >> x;
 
    // calling getFactorization function
    vector<int> p = getf(x);
 
    for (int i = 0; i < p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}